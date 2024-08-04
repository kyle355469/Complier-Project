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
#define YYDEBUG 1

char* nowIDName;
char* nowIDName2;
char* nowValue;
char* nowFuncName;
int exprChecker = 0;
int functionCall_counter = 0;       // count function's reference element
int outOfBlockCheck = 0;            // check if the block get any return or exit
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
%token ARRAY        BBEGIN
%token BOOL         CHAR        CONST       DECREASING  DEFAULT         // char? default?
%token DO           ELSE        END         T_EXIT      T_FALSE         // do?
%token FOR          FUNCTION    GET         T_IF        INT 
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
    大問題：test program 有 segmetation fault
*/
%%
// 第一行是要做什麼的
programs:   |    programs program
                ;

program:        pre_var_dec
            |    function_dec
            |    pre_stmt
                ;

identifier:     ID                                  // 有問題
                {
                    Trace("ID:");
                    Trace($1);
                    for(int i = 0; $1[i] != '\0'; i++){
                        nowIDName[i] = $1[i];
                        nowIDName[i + 1] = '\0';
                    }
                    $$ = typeLookUp(nowPointer, nowIDName, -1);
                }
            |   ID
                {
                    Trace("ID:");
                    Trace($1);
                    for(int i = 0; $1[i] != '\0'; i++){
                        nowIDName[i] = $1[i];
                        nowIDName[i + 1] = '\0';
                    }

                }
                U_BRACKET INT_NUM L_BRACKET
                {
                    int a = atoi($4);
                    //printf("%d\n", a);
                    if(!isInTheRange(nowPointer, nowIDName, a)){
                        yywarning("array index not in range");
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
            |   var_array_dec   {exprChecker = 0;}
            ;

// const a :string := "haha"
const_dec:      CONST identifier
                {
                    for(int i = 0; nowIDName[i] != '\0'; i++){
                        nowIDName2[i] = nowIDName[i];
                        nowIDName2[i + 1] = '\0';
                    }
                }
                GIVEN_EQUAL expr
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
                        constInsertion(nowPointer, nowIDName2, $5, nowValue);
                    }
                }
            |   CONST identifier
                {
                    for(int i = 0; nowIDName[i] != '\0'; i++){
                        nowIDName2[i] = nowIDName[i];
                        nowIDName2[i + 1] = '\0';
                    }
                }
                COLON type_dec GIVEN_EQUAL expr
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
                            if(nowPointer->t.id[a].type.type != $2.type){
                                yywarning("different type around assignment(:=)");
                            }
                            constInsertion(nowPointer, nowIDName2, $5, nowPointer->t.id[a].value);
                        }
                    }else{
                        Trace("const element generating...");
                        Trace(nowIDName);
                        //insert(nowPointer, nowIDName, $5, 1, -1);
                        
                        typeDef a = $7; 
                        if($5.type != a.type && !($5.type == real_type && a.type == bool_type || a.type == int_type)){
                            yywarning("wrong assignment for const variable");
                        }    
                        constInsertion(nowPointer, nowIDName, $5, nowValue);
                    }
                    
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
const_val_expr: STR_CONT    {$$ = $1;}
            |   INT_NUM     {$$ = $1;}
            |   REAL_NUM    {$$ = $1;}
            |   T_TRUE      {$$ = "true";}
            |   T_FALSE     {$$ = "false";}
            ;
// var b :int := 33
var_dec:        VAR identifier COLON type_dec GIVEN_EQUAL expr
                {
                    Trace("var element generating...");
                    Trace(nowIDName);
                    if($4.type != $6.type && !($4.type == real_type && $6.type == bool_type || $6.type == int_type)){
                        yywarning("wrong assignment for var variable");
                    } 
                    insert(nowPointer, nowIDName, $4, 0, -1);
                }
            |   VAR identifier GIVEN_EQUAL expr
                {
                    Trace("var element generating...");
                    Trace(nowIDName);
                    typeDef a = $4;      
                    insert(nowPointer, nowIDName, a, 0, -1);
                } 
            |   VAR identifier COLON type_dec
                {
                    Trace("var element generating...");
                    Trace(nowIDName);
                    insert(nowPointer, nowIDName, $4, 0, -1);
                }
            ;

// var c: array 1..10 of string
var_array_dec:  VAR identifier COLON ARRAY INT_NUM DOT DOT INT_NUM OF type_dec 
                {
                    int st = atoi($5);
                    int ed = atoi($8);
                    //printf("%s\n", nowIDName);
                    char* a = (char*)malloc(50);
                    int j;
                    for(j = 0; nowIDName[j] != '\0'; j++){
                        a[j] = nowIDName[j];
                    }
                    arrayInsertion(nowPointer, a, $10, st, ed);
                    // for(int i = st; i <= ed; i++){
                    //     char* k = intToChar(i);
                    //     printf("%c\n", k[0]);
                        
                    //     int size = strlen(nowIDName) + strlen(k) + 1;
                    //     a[j] = '[';
                    //     for(int l = j + 1; l < size; l++){
                    //         a[l] = k[l - j - 1];
                    //     }
                    //     a[size] = ']';
                    //     insert(nowPointer, a, $10, 0, i-st);
                    // }
                    Trace("array declear");
                }
            ;

// -------------------------------------------------
// functional decleration
function_dec:   
            |   function_def 
                programs
                END identifier
                {
                    if (!outOfBlockCheck){
                        nowPointer = nowPointer->l;
                        Trace("out one block");
                    }
                    outOfBlockCheck = 0;
                }
            |   PROCEDURE identifier 
                {
                    nowPointer = createTable(nowPointer, tailPointer, nowIDName, linenum);
                    tailPointer = nowPointer;
                }   
                U_PAREN argument_dec L_PAREN
                programs
                END identifier 
                {
                    if (!outOfBlockCheck){
                        nowPointer = nowPointer->l;
                        Trace("out one block");
                    }
                    outOfBlockCheck = 0;
                }
            ;

function_def:   FUNCTION identifier
                {
                    nowPointer = createTable(nowPointer, tailPointer, nowIDName, linenum);
                    tailPointer = nowPointer;
                    Trace("inside function Table");
                    Trace(nowIDName);
                } 
                U_PAREN argument_dec L_PAREN COLON type_dec
                {
                    Trace("function return type set:");
                    Trace(t_name[$8.type]);
                    setReturnType(nowPointer, $8);
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
                }
            |   identifier COLON ARRAY INT_NUM DOT DOT INT_NUM OF type_dec
                {
                    int st = atoi($4);
                    int ed = atoi($7);
                    char* a = (char*)malloc(50);
                    int j;
                    for(j = 0; nowIDName[j] != '\0'; j++){
                        a[j] = nowIDName[j];
                    }
                    arrayInsertion(nowPointer->innerLink, a, $9, st, ed);
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
                    nowPointer = createTable(nowPointer, tailPointer, "begin_block", linenum);
                    tailPointer = nowPointer;
                }
                program END
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

simple_statment:    identifier
                    {
                        for(int i = 0; nowIDName[i] != '\0'; i++){
                            nowIDName2[i] = nowIDName[i];
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
                        if(b != NULL){
                            //printf("%s\n", b->tableName);
                            if($1.type != b->returnType.type){
                                yywarning("cannot assign value due to wrong type");
                            }
                        }
                    }
                |   PUT{exprChecker = 0;} expr    
                    {
                        $$ = $3;
                        if (exprChecker == 2){
                            int a = allLookUp(nowPointer, nowIDName);
                            //printf("%d\n", a);
                            if(a == -1){
                                yywarning("variable not exist");
                            }
                        }
                    }
                |   GET identifier
                    {
                        $$ = $2;
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

                    }
                |   RETURN
                    {
                        if (!outOfBlockCheck){
                            outOfBlockCheck = 1;
                            nowPointer = nowPointer->l;
                            Trace("out one block");
                        }

                    }
                |   T_EXIT cond_check
                    {
                        if (!outOfBlockCheck){
                            outOfBlockCheck = 1;
                            nowPointer = nowPointer->l;
                            Trace("out one block");
                        }
                    }
                |   SKIP
                ;
// when 可以統一要刮號嗎
cond_check:     |   WHEN expr
                ;

cond_statment:      T_IF
                    {
                        nowPointer = createTable(nowPointer, tailPointer, "if_block", linenum);
                        tailPointer = nowPointer;
                    }
                    U_PAREN expr L_PAREN THEN
                    program else_block
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
                    program END T_IF
                    {
                        if (!outOfBlockCheck){
                            nowPointer = nowPointer->l;
                            Trace("out one block");
                        }
                        outOfBlockCheck = 0;
                    }
                |   END T_IF
                    {
                        if (!outOfBlockCheck){
                            nowPointer = nowPointer->l;
                            Trace("out one block");
                        }
                        outOfBlockCheck = 0;
                    }
                ;
// for 的 範圍 是const_expr 
loop_statment:      LOOP
                    {
                        nowPointer = createTable(nowPointer, tailPointer, "loop_block", linenum);
                        tailPointer = nowPointer;
                    }
                    program END LOOP
                    {
                        if (!outOfBlockCheck){
                            nowPointer = nowPointer->l;
                            Trace("out one block");
                        }
                        outOfBlockCheck = 0;
                    }
                |   FOR
                    {
                        nowPointer = createTable(nowPointer, tailPointer, "for_loop_block", linenum);
                        tailPointer = nowPointer;
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
                        //insert(nowPointer, nowIDName, a, 0, -1);
                    }
                    COLON expr
                    {
                        typeDef a;
                        a.type = int_type;
                        if($7.type != a.type){
                            yywarning("loop lower range must be type of int");
                        }
                    }
                    DOT DOT expr
                    {
                        typeDef a;
                        a.type = int_type;
                        if($11.type != a.type){
                            yywarning("loop upper range must be type of int");
                        }
                    }
                    program END FOR
                    {
                        if (!outOfBlockCheck){
                            nowPointer = nowPointer->l;
                            Trace("out one block");
                        }
                        outOfBlockCheck = 0;
                    }
                         // for index:1..n
                ;

decreasing:      
                |   DECREASING
                ;

func_proc_call:     identifier
                    {
                        //printf("%s\n", nowIDName);
                        for(int i = 0; nowIDName[i] != '\0'; i++){
                            nowFuncName[i] = nowIDName[i];
                            nowFuncName[i + 1] = '\0';
                        }

                        LT* func_tab = findTable(tailPointer, nowFuncName);
                        //printf("%s\n", func_tab->tableName);
                        if(func_tab == NULL){
                            yywarning(strcat(strcat("no function with name ", nowFuncName) ," exsit"));
                        }
                        typeDef a = tableReturnType(func_tab, nowFuncName);
                        $$ = a;
                        printf("%s\n", t_name[a.type]);
                    }
                    func_call_input
                    {
                        LT* func_tab = findTable(tailPointer, nowFuncName);
                        
                        if (func_tab->innerLink->t.tableSize != functionCall_counter){
                            yywarning(strcat(strcat("not the correct form for function ", nowFuncName), " "));
                        }
                        functionCall_counter = 0;
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
            }
        |   U_PAREN expr L_PAREN    {$$ = $2;}
        |   identifier              
            {
                $$ = $1; 
                exprChecker = 2;   
            }
        |   func_proc_call          {$$ = $1;}
        |   expr L_T expr           
            {
                exprChecker = 1;
                typeDef a;
                a.type = bool_type;
                if($1.type != $3.type){
                    yywarning("not same type around <=");
                }
                $$ = a;
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
    nowIDName = (char*)malloc(50);
    nowIDName2 = (char*)malloc(50);
    nowFuncName = (char*)malloc(50);
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


