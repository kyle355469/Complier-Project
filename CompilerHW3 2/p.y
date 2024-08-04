%{
#ifndef TABLE_DIF
#define TABLE_DIF
#include "table.h"
#endif

#define Trace(t)        if(NMode) {printf("\t-note: %s\n", t);}
int yylex();
int yyerror(const char *);
void yywarning(const char *msg);

#ifndef STDIO_DIF
#define STDIO_DIF
#include <stdio.h>
#endif

#ifndef STDLIB_DIF
#define STDLIB_DIF
#include <stdlib.h>
#endif

#ifndef STRING_DIF
#define STRING_DIF
#include <string.h>
#endif



LT* nowPointer;
LT* tailPointer;
extern int linenum;
extern FILE *yyin;
extern int yydebug;

FILE *out;

#define YYDEBUG 1

char* nowIDName;
char* nowIDName2;
char* nowIDName3;
char* nowValue;
char* nowFuncName;
char* nowFuncName2;
char* name;
char* funcType;
int exprChecker = 0;
int functionCall_counter = 0;       // count function's reference element
int outOfBlockCheck = 0;            // check if the block get any return or exit
int isInBlock = 0;
int NowScopeCount = 1;
int isNew = 0;
int isInIf = 0;

int ifCheck = 0;
int ifMin = 0;
int ifNow = 0;
int ifMax = 0;

int isDecrease = 0;
int firstForCounter=0;
int isInFunc = 0;
int isCalling = 0;
int isInLoop = 0;

char* nowType;
char* nowCommand;
const int NMode = 0;

const char* t_name[] = {"","int", "real", "bool", "string", "non"};

%}



%union {
    typeDef type;
    char* input;
};
/* tokens */
%token DOT          COMMA       COLON       SEMICOLON           //  分號？
%token U_PAREN      L_PAREN     U_BRACKET   L_BRACKET
%token U_B_PAREN    L_B_PAREN           // 大括號？

%token GIVEN_EQUAL
%token BBEGIN
%token BOOL         CHAR        CONST       DECREASING  DEFAULT         // char? default?
%token DO           ELSE        END         T_EXIT      T_FALSE         // do?
%token FOR          FUNCTION    T_IF        INT 
%token LOOP         OF          PUT         PROCEDURE   REAL
%token RESULT       RETURN      SKIP        STRING      THEN
%token T_TRUE       VAR         WHEN        

%token <input> ID
%token <input> INT_NUM
%token <input> REAL_NUM
%token <input> STR_CONT

%left AND OR
%left  PLUS         MINUS
%left  TIMES        DIV         MOD
%right UMINUS
%left NOT

%type <type> type_dec
%type <input> const_val_expr
%type <type> expr
%type <type> func_proc_call
%type <type> simple_statment
%type <type> identifier


// nonassociative 代表有 associative 問題就是 syntax error
// a := b := c? (>, <, <=, >=, =, not=)
%nonassoc L_T       EL_T        M_T         EM_T        EQUAL       NOT_EQ


/*
    大問題：test program 有 segmetation fault40
*/
%%
// 第一行是要做什麼的
programss:      pre_var_dec function_dec
                {
                    fprintf(out, "\tmethod public static void main(java.lang.String[])\n");
                    fprintf(out, "\tmax_stack 15\n");
                    fprintf(out, "\tmax_locals 15\n");
                    fprintf(out, "\t{\n");
                    NowScopeCount = 2;
                } pre_stmt
                {
                    fprintf(out, "\t\treturn\n");
                    fprintf(out, "\t}\n");
                    fprintf(out, "}\n");
                }
            ;

programs:   |   program programs
            ;

program:        pre_var_dec
            |   pre_stmt
            ;


identifier:     ID                                  
                {
                    Trace("ID:");
                    Trace($1);
                    for(int i = 0; $1[i] != '\0'; i++){
                        nowIDName[i] = $1[i];
                        nowIDName[i + 1] = '\0';
                    }
                    Symbol a = getNode(nowPointer, nowIDName);
                    if ( a.index != -100 && isNew == 0) {
                        if ( a.isConst == 1 ) {
                            if (a.type.type == int_type){
                                printTab(NowScopeCount);
                                fprintf(out, "sipush %s\n", a.value);
                            }else if (a.type.type == bool_type){
                                if(strcmp(a.value,"true")){
                                    printTab(NowScopeCount);
                                    fprintf(out, "iconst_1\n");
                                }else{
                                    printTab(NowScopeCount);
                                    fprintf(out, "iconst_0\n");
                                }
                            }else if (a.type.type == str_type){
                                printTab(NowScopeCount);
                                fprintf(out, "ldc \"%s\"", a.value);
                            }
                        }else{
                            LT* getter = getNodesScope(nowPointer, nowIDName);
                            //printf("%s \n", getter->tableName);
                            if(isInFunc == 1){
                                Symbol a = getNode(getter->innerLink, nowIDName);
                                printTab(NowScopeCount);
                                
                                fprintf(out, "iload %d\n", a.index);
                                
                            }else{
                                printTab(NowScopeCount);
                                if (!strcmp(getter->tableName, "main")) {
                                    fprintf(out, "getstatic int %s.%s\n", name, a.name);
                                }else{
                                    fprintf(out, "iload %d\n", a.index);
                                }
                            }
                                
                            
                        }
                    }
                    $$ = typeLookUp(nowPointer, nowIDName, -1);
                }
            ;

// -------------------------------------------------
// variable decleration
pre_var_dec:    
            |   variable_dec
            ;
variable_dec:   variable_dec variable_type
            |   variable_type
            ;

// const var & var array
variable_type:  const_dec       {exprChecker = 0;}
            |   var_dec         {exprChecker = 0;}
            ;

// const a :string := "haha"
const_dec:      CONST {isNew = 1;}identifier
                {
                    for(int i = 0; nowIDName[i] != '\0'; i++){
                        nowIDName2[i] = nowIDName[i];
                        nowIDName2[i + 1] = '\0';
                    }
                    
                } const_back
                ;
const_back:     GIVEN_EQUAL expr
                {
                    if (exprChecker == 1){
                        yywarning("no support expression calculate inside count variable");
                    }
                    if (exprChecker == 2){
                        int a = lookup(nowPointer, nowIDName);
                        if(a != -1){
                            if(!nowPointer->t.id[a].isConst){
                                yywarning("can't assign variable to const");
                            }
                            constInsertion(nowPointer, nowIDName2, nowPointer->t.id[a].type, nowPointer->t.id[a].value);
                        }
                    }else{
                        constInsertion(nowPointer, nowIDName2, $2, nowValue);
                    }
                    isNew = 0;
                }
            |   COLON type_dec GIVEN_EQUAL expr
                {
                    if (exprChecker == 1){
                        yywarning("no support expression calculate inside count variable");
                    }   
                    if (exprChecker == 2){
                        int a = lookup(nowPointer, nowIDName);
                        if(a != -1){
                            if(!nowPointer->t.id[a].isConst){
                                yywarning("can't assign variable to const");
                            }
                            constInsertion(nowPointer, nowIDName2, $2, nowPointer->t.id[a].value);
                        }
                    }else{
                        Trace("const element generating...");
                        Trace(nowIDName);
                        //insert(nowPointer, nowIDName, $2, 1, -1);
                        
                        typeDef a = $4; 
                        if($2.type != a.type && !($2.type == real_type && a.type == bool_type || a.type == int_type)){
                            yywarning("wrong assignment for const variable");
                        }    
                        constInsertion(nowPointer, nowIDName, $2, nowValue);
                    }
                    isNew = 0;
                    
                }
            ;

// const 可以 array 嗎 -> 不行
type_dec:       BOOL    
                {
                    typeDef a;
                    a.type = bool_type;
                    $$ = a;
                }
            |   STRING  
                {
                    typeDef a;
                    a.type = str_type;
                    $$ = a;
                }
            |   INT     
                {
                    typeDef a;
                    a.type = int_type;
                    $$ = a;
                }
            |   REAL  
                {
                    typeDef a;
                    a.type = real_type;
                    $$ = a;
                }
            ;


// 要補檢查
const_val_expr: STR_CONT    {$$ = $1;   nowType = "str";}
            |   INT_NUM     {$$ = $1;   nowType = "int";}
            |   REAL_NUM    {$$ = $1;   nowType = "real";}
            |   T_TRUE      
            {
                $$ = "true";   
                nowType = "bool";
                if (isInIf == 1) {
                    nowCommand = "ifeq ";
                    isInIf = 0;
                }
            }
            |   T_FALSE     
            {   
                $$ = "false";  
                nowType = "bool";
                if (isInIf == 1) {
                    nowCommand = "ifeq ";
                    isInIf = 0;
                }
            }
            ;
// var b :int := 33
var_dec:        VAR identifier COLON type_dec GIVEN_EQUAL const_val_expr
                {

                    Trace("var element generating...");
                    Trace(nowIDName);
                    insert(nowPointer, nowIDName, $4, 0, -1);
                    if (!isInBlock) {
                        printTab(NowScopeCount);
                        fprintf(out, "field static ");
                        if ($4.type == int_type){
                            fprintf(out, "int %s = %s\n",nowIDName, $6);
                        }else if ($4.type == bool_type){
                            fprintf(out, "bool %s = %s\n",nowIDName, $6);
                        }
                    }
                    else {
                        printTab(NowScopeCount);
                        fprintf(out, "sipush %s\n", $6);
                        printTab(NowScopeCount);
                        fprintf(out, "istore %d\n", allLookUp(nowPointer, nowIDName));
                    }
                    
                }
            |   VAR identifier GIVEN_EQUAL const_val_expr
                {
                    Trace("var element generating...");
                    Trace(nowIDName);
                    typeDef a = typeCheck($4);      
                    insert(nowPointer, nowIDName, a, 0, -1);
                    if (!isInBlock) {
                        printTab(NowScopeCount);
                        fprintf(out, "field static ");
                        if (a.type == int_type){
                            fprintf(out, "int %s = %s\n",nowIDName, $4);
                        }else if (a.type == bool_type){
                            fprintf(out, "bool %s = %s\n",nowIDName, $4);
                        }
                    }else{
                        printTab(NowScopeCount);
                        fprintf(out, "sipush %s\n", $4);
                        printTab(NowScopeCount);
                        fprintf(out, "istore %d\n", allLookUp(nowPointer, nowIDName));
                    }
                    
                } 
            |   VAR identifier COLON type_dec
                {
                    Trace("var element generating...");
                    Trace(nowIDName);
                    insert(nowPointer, nowIDName, $4, 0, -1);
                    if (!isInBlock) {
                        printTab(NowScopeCount);
                        fprintf(out, "field static ");
                        if ($4.type == int_type){
                            fprintf(out, "int %s\n",nowIDName);
                        }else if ($4.type == bool_type){
                            fprintf(out, "bool %s\n",nowIDName);
                        }
                    }
                }
            ;



// -------------------------------------------------
// functional decleration
function_dec:   
            |   function_def { isInBlock = 1; isInFunc = 1;}
                programs
                END identifier
                {
                    if (!outOfBlockCheck){
                        nowPointer = nowPointer->l;
                        Trace("out one block");
                    }
                    outOfBlockCheck = 0;
                    NowScopeCount--;
                    printTab(NowScopeCount);
                    fprintf(out, "}\n");
                    isInFunc = 0;
                }
            |   PROCEDURE identifier 
                {
                    nowPointer = createTable(nowPointer, tailPointer, nowIDName, linenum);
                    tailPointer = nowPointer;
                }   
                U_PAREN argument_dec L_PAREN {isInBlock = 1;isInFunc = 1;}
                programs
                END identifier 
                {
                    if (!outOfBlockCheck){
                        nowPointer = nowPointer->l;
                        Trace("out one block");
                    }
                    outOfBlockCheck = 0;
                    NowScopeCount--;
                    printTab(NowScopeCount);
                    fprintf(out, "}\n");
                    isInFunc = 0;
                }
            ;

function_def:   FUNCTION identifier
                {
                    nowPointer = createTable(nowPointer, tailPointer, nowIDName, linenum);
                    tailPointer = nowPointer;
                    Trace("inside function Table");
                    Trace(nowIDName);
                    for(int i =0; nowIDName[i] != '\0'; i++){
                        nowFuncName[i] = nowIDName[i];
                        nowFuncName[i + 1] = '\0';
                    }
                    isNew = 1;
                } 
                U_PAREN argument_dec L_PAREN COLON type_dec
                {
                    Trace("function return type set:");
                    Trace(t_name[$8.type]);
                    setReturnType(nowPointer, $8);
                    printTab(NowScopeCount);
                    fprintf(out, "method public static ");
                    if ($8.type == int_type){
                        fprintf(out, "int ");
                    }else if ($8.type == bool_type){
                        fprintf(out, "bool");
                    }
                    fprintf(out, "%s(", nowFuncName);
                    LT* funcT = findTable(nowPointer, nowFuncName);
                    if(funcT != NULL){
                        for(int i = 0; i < funcT->innerLink->t.tableSize; i++){
                            if(funcT->innerLink->t.id[i].type.type == int_type){
                                fprintf(out, "int");
                            }else if(funcT->innerLink->t.id[i].type.type == bool_type){
                                fprintf(out, "bool");
                            }
                            if(i + 1 < funcT->innerLink->t.tableSize){
                                fprintf(out, ", ");
                            }
                        }
                        fprintf(out, ")\n");
                        printTab(NowScopeCount);
                        fprintf(out, "max_stack 15\n");
                        printTab(NowScopeCount);
                        fprintf(out, "max_locals 15\n");
                        printTab(NowScopeCount);
                        fprintf(out, "{\n");
                        NowScopeCount++;
                    }
                    isNew = 0;
                }
                
            ;

// 前後括號 中間任意數量 identifier
argument_dec:   
            |   argument_dec COMMA identi_req
            |   identi_req
            ;

// e.g.     a :int, b:string
identi_req:     identifier COLON type_dec
                {
                    insert(nowPointer->innerLink, nowIDName, $3, 0, -1); // function input 有const嗎
                    printf("insert success %s\n", nowIDName);
                }
                ;

// -------------------------------------------------
// statments
pre_stmt:   
            |   statments
            ;

statments:      statments statment
            |   statment
            ;

statment:       BBEGIN
                {
                    isInBlock = 1;
                    nowPointer = createTable(nowPointer, tailPointer, "begin_block", linenum);
                    tailPointer = nowPointer;
                }
                programs END
                {
                    if (!outOfBlockCheck){
                        nowPointer = nowPointer->l;
                        Trace("out one block");
                    }
                    outOfBlockCheck = 0;
                }
            |   simple_statment         
            |   cond_statment           // if
            |   loop_statment           // loop & for
            |   func_proc_call
            //|   expr    // 很有問題
            ;

simple_statment:    ID
                    {
                        for(int i = 0; $1[i] != '\0'; i++){
                            nowIDName2[i] = $1[i];
                            nowIDName2[i + 1] = '\0';
                        }
                    }
                    GIVEN_EQUAL expr // assignment 可能要獨立出來寫
                    {
                        Trace(nowIDName);
                        int a = changeValue(nowPointer, nowIDName2);
                        LT* b = findTable(tailPointer, nowIDName);
                        typeDef c = typeLookUp(nowPointer, nowIDName, -1);
                        //printf("%s\n", nowIDName);
                        if (a == -1){
                            yywarning("no variable exist");
                        }else if (a == -2){
                            yywarning("type const cannot be modify");
                        }
                        // if (b == NULL && c.type != $1.type){
                        //     yywarning("different type around assignment(:=)");
                        // }   
                        
                        Symbol node = getNode(nowPointer, nowIDName2);
                        LT* getter = getNodesScope(nowPointer, nowIDName2);
                        if (!strcmp(getter->tableName, "main")) {
                            printTab(NowScopeCount);
                            fprintf(out, "putstatic ");
                            if (node.type.type == int_type){
                                fprintf(out, "int ");
                            }else if (node.type.type == bool_type){
                                fprintf(out, "bool ");
                            }
                            fprintf(out, "%s.%s\n", name, node.name);
                        }else{
                            printTab(NowScopeCount);
                            fprintf(out, "istore %d\n", node.index);
                        }
                    }
                |   PUT
                    {
                        exprChecker = 0;
                        printTab(NowScopeCount);
                        fprintf(out, "getstatic java.io.PrintStream java.lang.System.out\n");
                    } 
                    expr    
                    {
                        $$ = $3;
                        if (exprChecker == 2){
                            int a = allLookUp(nowPointer, nowIDName);
                            //printf("%d\n", a);
                            if(a == -1){
                                yywarning("variable not exist");
                            }
                        }
                        
                        printTab(NowScopeCount);
                        if(isCalling == 1){
                            if(!strcmp(funcType, "int")){
                                fprintf(out, "invokevirtual void java.io.PrintStream.println(int)\n");
                            }else{

                            }
                            isCalling = 0;
                        }
                        else if(!strcmp(nowType,"str")){
                            fprintf(out, "invokevirtual void java.io.PrintStream.print(java.lang.String)\n");
                        }else{
                            fprintf(out, "invokevirtual void java.io.PrintStream.println(int)\n");
                        }
                    }
                |   RESULT expr
                    {
                        typeDef a = typeCalculateCheck(tableReturnType(nowPointer, nowPointer->tableName), $2);
                        if(a.type == $2.type){
                            $$ = $2;
                        }else{
                            yywarning("wrong return type");
                            // 隱式行變轉換？ -> done
                        }
                        if (!outOfBlockCheck){
                            outOfBlockCheck = 1;
                            nowPointer = nowPointer->l;
                            Trace("out one block");
                        }
                        printTab(NowScopeCount);
                        fprintf(out, "ireturn\n");

                    }
                |   RETURN
                    {
                        if (!outOfBlockCheck){
                            outOfBlockCheck = 1;
                            nowPointer = nowPointer->l;
                            Trace("out one block");
                        }
                        printTab(NowScopeCount);
                        fprintf(out, "return\n");

                    }
                |   T_EXIT{isInLoop = 1;} cond_check
                    {
                        if (!outOfBlockCheck){
                            outOfBlockCheck = 1;
                            nowPointer = nowPointer->l;
                            Trace("out one block");
                        }
                    }
                |   SKIP{
                        printTab(NowScopeCount);
                    fprintf(out, "getstatic java.io.PrintStream java.lang.System.out\n");
                        printTab(NowScopeCount);
                    fprintf(out, "invokevirtual void java.io.PrintStream.println()\n");
                }
                ;
// when 可以統一要刮號嗎
cond_check:     |   WHEN expr
                    {
                        fprintf(out, "Ltrue%d\n", ifNow);
                        printTab(NowScopeCount);
                        fprintf(out, "iconst_0\n");
                        printTab(NowScopeCount);
                        fprintf(out, "goto Lfalse%d\n", ifNow);
                        fprintf(out, "Ltrue%d:\n", ifNow);
                        printTab(NowScopeCount);
                        fprintf(out, "iconst_1\n");
                        fprintf(out, "Lfalse%d:\n", ifNow);
                        printTab(NowScopeCount);
                        fprintf(out, "ifne Lexit%d\n", ifNow);
                    }
                ;

cond_statment:      T_IF
                    {
                        nowPointer = createTable(nowPointer, tailPointer, "if_block", linenum);
                        tailPointer = nowPointer;
                        isInBlock = 1;
                        isInIf = 1;

                        if (ifCheck == 1){
                            ifNow = ifMax + 1;
                            ifMin = ifMax++;
                            ifCheck = 0;
                        }
                        else{
                            ifNow += 1;
                        }

                        if(ifNow > ifMax){
                            ifMax = ifNow;
                        }
                    }
                    expr {
                        if (isInIf == 0){
                            printTab(NowScopeCount);
                            fprintf(out, "%s ", nowCommand);
                        }
                        fprintf(out, "Lfalse%d\n", ifNow);
                    } THEN
                    programs {
                        printTab(NowScopeCount);
                        fprintf(out, "goto Lexit%d\n", ifNow);
                        fprintf(out, "Lfalse%d:\n", ifNow);
                    }else_block
                ;
else_block:         ELSE
                    {
                        if (!outOfBlockCheck){
                            nowPointer = nowPointer->l;
                            Trace("out one block");
                        }
                        outOfBlockCheck = 0;
                        nowPointer = createTable(nowPointer, tailPointer, "else_block", linenum);
                        tailPointer = nowPointer;
                    }
                    programs end_if 
                |   end_if
                    ;
end_if:             END T_IF
                    {
                        if (!outOfBlockCheck){
                            nowPointer = nowPointer->l;
                            Trace("out one block");
                        }
                        outOfBlockCheck = 0;
                        fprintf(out, "Lexit%d:\n", ifNow);
                        
                        ifNow--;
                        if( ifNow == ifMin ){
                            ifCheck = 1;
                        }
                    }
                    ;
// for 的 範圍 是const_expr 
loop_statment:      LOOP
                    {
                        nowPointer = createTable(nowPointer, tailPointer, "loop_block", linenum);
                        tailPointer = nowPointer;
                        if (ifCheck == 1){
                            ifNow = ifMax + 1;
                            ifMin = ifMax++;
                            ifCheck = 0;
                        }
                        else{
                            ifNow += 1;
                        }

                        if(ifNow > ifMax){
                            ifMax = ifNow;
                        }
                        fprintf(out, "Lbegin%d:\n", ifNow);
                        isInBlock = 1;
                        isInIf = 1;
                        isInLoop = 1;
                        
                    }
                    programs END LOOP
                    {
                        if (!outOfBlockCheck){
                            nowPointer = nowPointer->l;
                            Trace("out one block");
                        }
                        outOfBlockCheck = 0;
                        printTab(NowScopeCount);
                        fprintf(out, "goto Lbegin%d\n", ifNow);
                        fprintf(out, "Lexit%d:\n", ifNow);
                        ifNow--;
                        if( ifNow == ifMin ){
                            ifCheck = 1;
                        }
                        isInLoop = 0;
                    }
                |   FOR
                    {
                        nowPointer = createTable(nowPointer, tailPointer, "for_loop_block", linenum);
                        tailPointer = nowPointer;
                        isInBlock = 1;
                        if (ifCheck == 1){
                            ifNow = ifMax + 1;
                            ifMin = ifMax++;
                            ifCheck = 0;
                        }
                        else{
                            ifNow += 1;
                        }

                        if(ifNow > ifMax){
                            ifMax = ifNow;
                        }
                        isInBlock = 1;
                        isInIf = 1;
                        isNew = 1;
                    }
                    decreasing identifier
                    {
                        typeDef a;
                        a.type = int_type;
                        int b = lookup(nowPointer->l, nowIDName);
                        if(b == -1){
                            yywarning("no variable exist");
                        }
                        if(b != -1 && nowPointer->l->t.id[b].type.type != int_type){
                            yywarning("variable no int type");
                        }
                        for(int i = 0; nowIDName[i] != '\0'; i++){
                            //printf("%c\n", nowIDName[i]);
                            nowIDName3[i] = nowIDName[i];
                            nowIDName3[i + 1] = '\0';
                        }isNew = 0;
                        //insert(nowPointer, nowIDName, a, 0, -1);
                    }
                    COLON expr
                    {
                        typeDef a;
                        a.type = int_type;
                        if($7.type != a.type){
                            yywarning("loop lower range must be type of int");
                        }
                        Symbol gg = getNode(nowPointer, nowIDName3);
                        printTab(NowScopeCount);
                        fprintf(out, "putstatic ");
                        if(gg.type.type == int_type){
                            fprintf(out, "int ");
                        }else if(gg.type.type == bool_type){
                            fprintf(out, "bool ");
                        } 
                        fprintf(out, "%s.%s\n", name, nowIDName3);
                        
                    }
                    DOT DOT 
                    {
                        fprintf(out, "Lbegin%d:\n", ifNow);
                        Symbol gg = getNode(nowPointer, nowIDName3);
                        printTab(NowScopeCount);
                        fprintf(out, "getstatic ");
                        if(gg.type.type == int_type){
                            fprintf(out, "int ");
                        }else if(gg.type.type == bool_type){
                            fprintf(out, "bool ");
                        } 
                        fprintf(out, "%s.%s\n", name, nowIDName3);
                    }
                    expr
                    {
                        typeDef a;
                        a.type = int_type;
                        if($12.type != a.type){
                            yywarning("loop upper range must be type of int");
                        }
                        printTab(NowScopeCount);
                        fprintf(out, "isub\n");
                        if (isDecrease == 1){
                            printTab(NowScopeCount);
                            fprintf(out, "iflt ");
                        }else{
                            printTab(NowScopeCount);
                            fprintf(out, "ifgt ");
                        }
                        fprintf(out, "Ltrue%d\n", ifNow);
                        printTab(NowScopeCount);
                        fprintf(out, "iconst_0\n");
                        printTab(NowScopeCount);
                        fprintf(out, "goto Lfalse%d\n", ifNow);
                        fprintf(out, "Ltrue%d:\n", ifNow);
                        printTab(NowScopeCount);
                        fprintf(out, "iconst_1\n");
                        fprintf(out, "Lfalse%d:\n", ifNow);
                        printTab(NowScopeCount);
                        fprintf(out, "ifne Lexit%d\n", ifNow);
                    }
                    programs END FOR
                    {
                        if (!outOfBlockCheck){
                            nowPointer = nowPointer->l;
                            Trace("out one block");
                        }
                        outOfBlockCheck = 0;
                        Symbol gg = getNode(nowPointer, nowIDName3);
                        printTab(NowScopeCount);
                        fprintf(out, "getstatic ");
                        if(gg.type.type == int_type){
                            fprintf(out, "int ");
                        }else if(gg.type.type == bool_type){
                            fprintf(out, "bool ");
                        } 
                        fprintf(out, "%s.%s\n", name, nowIDName3);
                        printTab(NowScopeCount);
                        fprintf(out, "sipush 1\n");
                        if (isDecrease == 1){
                            printTab(NowScopeCount);
                            fprintf(out, "isub\n");
                        }else{
                            printTab(NowScopeCount);
                            fprintf(out, "iadd\n");
                        }
                        printTab(NowScopeCount);
                        fprintf(out, "putstatic ");
                        if(gg.type.type == int_type){
                            fprintf(out, "int ");
                        }else if(gg.type.type == bool_type){
                            fprintf(out, "bool ");
                        } 
                        fprintf(out, "%s.%s\n", name, nowIDName3);
                        printTab(NowScopeCount);
                        fprintf(out, "goto Lbegin%d\n", ifNow);
                        fprintf(out, "Lexit%d:\n", ifNow);
                        ifNow--;
                        if( ifNow == ifMin ){
                            ifCheck = 1;
                        }
                    }
                         // for index:1..n
                ;

decreasing:      
                |   DECREASING {isDecrease = 1;}
                ;

func_proc_call:     identifier
                    {
                        //printf("%s ahufkadfs\n", nowIDName);
                        for(int i = 0; nowIDName[i] != '\0'; i++){
                            //printf("%c\n", nowIDName[i]);
                            nowFuncName2[i] = nowIDName[i];
                            nowFuncName2[i + 1] = '\0';
                        }
                        
                        //printf("%s\n", nowFuncName2);
                        LT* func_tab = findTable(tailPointer, nowFuncName2);
                        //printf("%s ---------------------\n", func_tab->tableName);
                        if(func_tab == NULL){
                            yywarning(strcat(strcat("no function with name ", nowFuncName2) ," exsit"));
                        }
                        typeDef a = tableReturnType(func_tab, nowFuncName2);
                        $<type>$ = a;
                        //printf("%s\n", t_name[a.type]);
                        isCalling = 1;
                    }
                    func_call_input
                    {
                        //printf("start find %s\n", nowFuncName2);
                        LT* funcT = findTable(tailPointer, nowFuncName2);
                        printTab(NowScopeCount);
                        fprintf(out, "invokestatic ");
                        if(funcT != NULL){
                            if (funcT->innerLink->t.tableSize != functionCall_counter){
                                yywarning(strcat(strcat("not the correct form for function ", nowFuncName2), " "));
                            }
                            functionCall_counter = 0;
                            if(funcT->returnType.type == int_type){
                                fprintf(out, "int ");
                                funcType[0] = '\0';
                                strcat(funcType, "int");
                            }else if(funcT->returnType.type == bool_type){
                                fprintf(out, "bool ");
                                funcType[0] = '\0';
                                strcat(funcType, "int");
                            } 
                            fprintf(out, "%s.%s(", name, funcT->tableName);

                            for(int i = 0; i < funcT->innerLink->t.tableSize; i++){
                                if(funcT->innerLink->t.id[i].type.type == int_type){
                                    fprintf(out, "int");
                                }else if(funcT->innerLink->t.id[i].type.type == bool_type){
                                    fprintf(out, "bool");
                                }
                                if(i + 1 < funcT->innerLink->t.tableSize){
                                    fprintf(out, ", ");
                                }
                            }
                            fprintf(out, ")\n");
                        }
                    }
                ;

func_call_input:    U_PAREN L_PAREN
                |   U_PAREN func_input L_PAREN
                |   U_PAREN expr
                    {
                        //printf("--------------%s\n", nowFuncName);
                        //printf("table:%s\t now type:%u\n", nowPointer->tableName, $2.type);
                        LT* func_tab = findTable(tailPointer, nowFuncName);
                        //printf("table:%s\t now type:%u\n", func_tab->tableName, $2.type);
                        typeDef a = getFunctionInputType(func_tab, functionCall_counter);
                        functionCall_counter++;
                        if($2.type != a.type){
                            //printf("%s\n%s\n", t_name[$2.type], t_name[a.type]);
                            yywarning("uncorrect parameter type");
                        }
                    }
                    L_PAREN
                ;
// function 要的參數 （不確定對不對）
// fib(n, m)
func_input:         func_input COMMA expr
                    {
                        //printf("--------------%s\n", nowFuncName);
                        //printf("table:%s\t now type:%u\n", nowPointer->tableName, $3.type);
                        LT* func_tab = findTable(tailPointer, nowFuncName);
                        //printf("table:%s\t now type:%u\n", func_tab->tableName, $3.type);
                        typeDef a = getFunctionInputType(func_tab, functionCall_counter);
                        functionCall_counter++;
                        if($3.type != a.type){
                            //printf("%s\n%s\n", t_name[$3.type], t_name[a.type]);
                            yywarning("uncorrect parameter type");
                        }
                    }
                |   expr
                    {
                        //printf("--------------%s\n", nowFuncName);
                        //printf("table:%s\t now type:%u\n", nowPointer->tableName, $1.type);
                        LT* func_tab = findTable(tailPointer, nowFuncName);
                        //printf("table:%s\t now type:%u\n", func_tab->tableName, $1.type);
                        typeDef a = getFunctionInputType(func_tab, functionCall_counter);
                        functionCall_counter++;
                        if($1.type != a.type){
                            //printf("%s\n%s\n", t_name[$1.type], t_name[a.type]);
                            yywarning("uncorrect parameter type");
                        }
                    }
                    COMMA expr
                    {
                        //printf("--------------%s\n", nowFuncName);
                        //printf("table:%s\t now type:%u\n", nowPointer->tableName, $4.type);
                        LT* func_tab = findTable(tailPointer, nowFuncName);
                        //printf("table:%s\t now type:%u\n", func_tab->tableName, $4.type);
                        typeDef a = getFunctionInputType(func_tab, functionCall_counter);
                        functionCall_counter++;
                        if($4.type != a.type){
                            //printf("%s\n%s\n", t_name[$4.type], t_name[a.type]);
                            yywarning("uncorrect parameter type");
                        }
                    }
                ;

// procedure_call:     identifier func_call_input{Trace("proce call");}
                

// -------------------------------------------------
// expression
// 不會寫-.-
expr:       const_val_expr  
            {
                for(int i = 0; $1[i] != '\0'; i++){
                    nowValue[i] = $1[i];
                    nowValue[i + 1] = '\0';
                }
                $$ = typeCheck($1);  
                if (isNew == 0){
                    printTab(NowScopeCount);
                    if($$.type == int_type){
                        fprintf(out, "sipush %s\n", $1);  
                    }else if($$.type == bool_type){
                        if(strcmp($1 ,"true")){
                            fprintf(out, "iconst_1\n");
                        }else{
                            fprintf(out, "iconst_0\n");
                        }
                    }else if($$.type == str_type){
                        fprintf(out, "ldc \"%s\"\n", nowValue);
                    }
                }
            }
        |   expr PLUS expr
            {
                exprChecker = 1;
                typeDef a,b;
                a = $1;
                b = $3;
                typeDef c;
                c.type = str_type;
                typeDef check = typeCalculateCheck(a, b);
                if(a.type == c.type || b.type == c.type){
                    yywarning("warning: can't calculate string type");
                }
                $$ = check;
                printTab(NowScopeCount);
                fprintf(out, "iadd\n");
            }
        |   expr MINUS expr 
            {
                exprChecker = 1;
                typeDef a,b;
                a = $1;
                b = $3;
                typeDef c;
                c.type = str_type;
                typeDef check = typeCalculateCheck(a, b);
                if(a.type == c.type || b.type == c.type){
                    yywarning("warning: can't calculate string type");
                }
                $$ = check;
                printTab(NowScopeCount);
                fprintf(out, "isub\n");
            }    
        |   expr TIMES expr
            {
                exprChecker = 1;
                typeDef a,b;
                a = $1;
                b = $3;
                typeDef c;
                c.type = str_type;
                typeDef check = typeCalculateCheck(a, b);
                if(a.type == c.type || b.type == c.type){
                    yywarning("warning: can't calculate string type");
                }
                $$ = check;
                printTab(NowScopeCount);
                fprintf(out, "imul\n");
            }     
        |   expr DIV expr
            {
                exprChecker = 1;
                typeDef a,b;       // 要多check b 不能是 0
                a = $1;
                b = $3;
                typeDef c;
                c.type = str_type;
                typeDef check = typeCalculateCheck(a, b);
                if(a.type == c.type || b.type == c.type){
                    yywarning("warning: can't calculate string type");
                }
                $$ = check;
                printTab(NowScopeCount);
                fprintf(out, "idiv\n");
            }       
        |   expr MOD expr
            {
                exprChecker = 1;
                typeDef a,b;       // 要多check b 不能是 0 而且 b 要是 int 
                a = $1;
                b = $3;
                typeDef c;
                c.type = str_type;
                typeDef d;
                d.type = int_type;
                typeDef check = typeCalculateCheck(a, b);
                if(a.type == c.type || b.type == c.type){
                    yywarning("warning: can't calculate string type");
                }else if(b.type != d.type){
                    yywarning("right identifier must be int type!");
                }
                $$ = check;
                printTab(NowScopeCount);
                fprintf(out, "irem\n");
            }
        |   MINUS expr              %prec UMINUS    
            {
                exprChecker = 1;
                typeDef a = $2;
                typeDef b;
                b.type = str_type;
                if(a.type == b.type){
                    yywarning("can't plus minus in front of type string");
                }
                $$ = $2;
                printTab(NowScopeCount);
                fprintf(out, "ineg\n");
            }
        |   U_PAREN expr L_PAREN    {$$ = $2;}
        |   identifier              
            {
                $$ = $1; 
                exprChecker = 2;  
                if($1.type == int_type){
                    nowType = "int";
                }else if($1.type == bool_type){
                    nowType = "bool";
                }else if($1.type == str_type){
                    nowType = "str";
                }
                //printTab(NowScopeCount); 
                //fprintf(out, "iload %d\n", allLookUp(tailPointer, nowIDName));
            }
        |   func_proc_call          {$$ = $1;isCalling = 1;}
        |   expr L_T expr           
            {
                exprChecker = 1;
                typeDef a;
                a.type = bool_type;
                if($1.type != $3.type){
                    yywarning("not same type around <=");
                }
                $$ = a;
                printTab(NowScopeCount);
                fprintf(out, "isub\n");
                if(isInLoop == 1){
                    printTab(NowScopeCount);
                    fprintf(out, "iflt ");
                }else{
                    printTab(NowScopeCount);
                    fprintf(out, "ifge ");
                }
            }
        |   expr EL_T expr
            {
                exprChecker = 1;
                typeDef a;
                a.type = bool_type;
                if($1.type != $3.type){
                    yywarning("not same type around <");
                }
                $$ = a;
                printTab(NowScopeCount);
                fprintf(out, "isub\n");
                if(isInLoop == 1){
                    printTab(NowScopeCount);
                    fprintf(out, "ifle ");
                }else{
                    printTab(NowScopeCount);
                    fprintf(out, "ifgt ");
                }
                
            }
        |   expr EM_T expr
            {
                exprChecker = 1;
                typeDef a;
                a.type = bool_type;
                if($1.type != $3.type){
                    yywarning("not same type around >=");
                }
                
                $$ = a;
                printTab(NowScopeCount);
                fprintf(out, "isub\n");
                if(isInLoop == 1){
                    printTab(NowScopeCount);
                    fprintf(out, "ifge ");
                }else{
                    printTab(NowScopeCount);
                    fprintf(out, "ifit ");
                }
            }
        |   expr M_T expr
            {
                exprChecker = 1;
                typeDef a;
                a.type = bool_type;
                if($1.type != $3.type){
                    yywarning("not same type around >");
                }
                $$ = a;
                printTab(NowScopeCount);
                fprintf(out, "isub\n");
                if(isInLoop == 0){
                    printTab(NowScopeCount);
                    fprintf(out, "ifle ");
                }else{
                    printTab(NowScopeCount);
                    fprintf(out, "ifgt ");
                }
            }
        |   expr EQUAL expr
            {
                exprChecker = 1;
                typeDef a;
                a.type = bool_type;
                if($1.type != $3.type){
                    yywarning("not same type around EQUAL(=)");
                }
                $$ = a;
                printTab(NowScopeCount);
                fprintf(out, "isub\n");
                printTab(NowScopeCount);
                fprintf(out, "ifeq ");
            }
        |   expr NOT_EQ expr  
            {
                exprChecker = 1;
                typeDef a;
                a.type = bool_type;
                if($1.type != $3.type){
                    yywarning("not same type around EQUAL(=)");
                }
                $$ = a;
                printTab(NowScopeCount);
                fprintf(out, "isub\n");
                printTab(NowScopeCount);
                fprintf(out, "ifne ");
            }   
        |   expr AND expr
            {
                exprChecker = 1;
                typeDef a;
                a.type = bool_type;
                if($1.type != a.type || $3.type != a.type){
                    yywarning("not bool value inside bool_expr");
                }
                $$ = a;
                printTab(NowScopeCount);
                fprintf(out, "iand\n");
            }
        |   expr OR expr
            {
                exprChecker = 1;
                typeDef a;
                a.type = bool_type;
                if($1.type != a.type || $3.type != a.type){
                    yywarning("not bool value inside bool_expr");
                }
                $$ = a;
                printTab(NowScopeCount);
                fprintf(out, "ior\n");
            }
        |   NOT expr
            {
                exprChecker = 1;
                typeDef a;
                a.type = bool_type;
                if($2.type != a.type){
                    yywarning("not bool value inside bool_expr");
                }
                $$ = a;
                printTab(NowScopeCount);
                fprintf(out, "ixor\n");
            }
        ;
%%
//#include "lex.yy.c"

int yyerror(const char *msg)
{
    fprintf(stderr, "\t---error: %s\n", msg);
    //fprintf(stderr, "%d\n", linenum);
    exit(0);
    return 0;
}

void yywarning(const char *msg)
{
    fprintf(stderr, "\t--warning: %s\n", msg);
    //fprintf(stderr, "%d\n", linenum);
}

int main(int argc, char* argv[])
{
    name = (char*)malloc(50);
    for(int i = 0; argv[argc - 1][i] != '\0'; i++){
        if(argv[argc - 1][i] == '.'){
            break;
        }
        name[i] = argv[argc - 1][i];
        name[i + 1] = '\0';
    }
    strcat(name, ".jasm");
    out = fopen(name, "w+");
    for(int i = 0; argv[argc - 1][i] != '\0'; i++){
        if(argv[argc - 1][i] == '.'){
            break;
        }
        name[i] = argv[argc - 1][i];
        name[i + 1] = '\0';
    }
    fprintf(out, "class %s\n{\n", name);
    nowIDName = (char*)malloc(50);
    funcType = (char*)malloc(50);
    nowIDName2 = (char*)malloc(50);
    nowIDName3 = (char*)malloc(50);
    nowFuncName = (char*)malloc(50);
    nowFuncName2 = (char*)malloc(50);
    nowValue = (char*)malloc(50);
    nowPointer = starter("main");
    tailPointer = nowPointer;
    /* open the source program file */
    if (argc < 2) {
        printf ("Usage: sc filename\n");
        //exit(1);
        return 0;
    }
    if(!strcmp(argv[1], "--debug")){
        yydebug = 1;
    }
    yyin = fopen(argv[argc - 1], "r");         /* open input file */

    /* perform parsing */
    if (yyparse() == 1)                 /* parsing */
        yyerror("Parsing error !");     /* syntax error */

    allTableDump(tailPointer);
}


