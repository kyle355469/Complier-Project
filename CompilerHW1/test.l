
%{
#define LIST     strcat(buf,yytext)
#define STRLIST  strcat(Strbuf, yytext)   
#define token(t) {LIST; if(debugMode) printf("<%s>\n",t);}
#define tokenInteger(t,i) {LIST; if(debugMode) printf("<%s:%d>\n",t,i);}
#define tokenString(t,s) {LIST; if(debugMode) printf("<%s:%s>\n",t,s);}

#define MAX_LINE_LENG 256
int linenum = 1;
char buf[MAX_LINE_LENG];
char Strbuf[MAX_LINE_LENG];
char* symbolTable[MAX_LINE_LENG];
int tableSize = 0;
int debugMode = 0;

int lookup(char *name){
    for(int i = 0; i < tableSize; i++){
        //printf("%s vs %s\n", symbolTable[i], name);
        if(!strcmp(symbolTable[i], name)){
            return i;
        }
    }
    return -1;
}

void insert(char *name, int leng){
    char *temp = malloc(leng);
    for(int i = 0; i < leng; i++){
        temp[i] = name[i];
    }
    symbolTable[tableSize++] = temp;
}

void dump(){
    printf("Symbol Table:\n");
    for(int i = 0; i < tableSize; i++){
        printf("symbol %d:\t%s\n", i + 1, symbolTable[i]);
    }
}
//{String}  {tokenString("String", yytext)}
%}
Id [a-zA-Z][0-9a-zA-Z]*

%x COMMENT STRING

%%
"."     {token(".")}
","     {token(",")}
":"     {token(":")}
";"     {token(";")}
"("     {token("(")}
")"     {token(")")}
"["     {token("[")}
"]"     {token("]")}
"{"     {token("{")}
"}"     {token("}")}
"+"     {token("+")}
"-"     {token("-")}
"*"     {token("*")}
"/"     {token("/")}
"mod"   {token("mod")}
":="    {token(":=")}
"<"     {token("<")}
"<="    {token("<=")}    
">="    {token(">=")}
">"     {token(">")}
"="     {token("=")}
"not="  {token("not=")}
"and"   {token("and")}
"or"    {token("or")}
"not"   {token("not")}
array   {token("ARRAY")}
begin   {token("BEGIN")}
bool    {token("BOOL")}
char    {token("CHAR")}
const   {token("CONST")}
decreasing  {token("DECREASING")}
default     {token("DEFAULT")}
do      {token("DO")}
else    {token("ELSE")}
end     {token("END")}
exit    {token("EXIT")}
false   {token("FALSE")}
for     {token("FOR")}
function    {token("FUNCTION")}
get     {token("GET")}
if      {token("IF")}
int     {token("INT")}
loop    {token("LOOP")}
of      {token("OF")}
put     {token("PUT")}
procedure   {token("PROCEDURE")}
real    {token("REAL")}
result  {token("RESULT")}
return  {token("RETURN")}
skip    {token("SKIP")}
string  {token("STRING")}
then    {token("THEN")}
true    {token("TRUE")}
var     {token("VAR")}
when    {token("WHEN")}
\"      {LIST; Strbuf[0] = '\0'; STRLIST; BEGIN STRING;}
<STRING>[^\n\"] {STRLIST;LIST;}

<STRING>\"\"    {LIST; strcat(Strbuf, "\"");}
<STRING>\"      {STRLIST;tokenString("string", Strbuf); BEGIN INITIAL;}

"\{\%"   {token("COMMENT"); BEGIN COMMENT;}
<COMMENT>[^\n\%\}]*  {LIST;}
<COMMENT>\n    {
                LIST;
                printf("%d: %s", linenum++, buf);
                buf[0] = '\0';
                }
<COMMENT>"%}"   {LIST; BEGIN INITIAL;}

([1-9][0-9]*|0)(\.[0-9]*)?  {tokenInteger("Numerical", atoi(yytext))}
{Id} {
        int pos = lookup(yytext);
        if (pos == -1){
            insert(yytext, yyleng);
            //printf("insert %s\n", yytext);
        }
        tokenString("id", yytext);
}
"%".*     {LIST;}

\n      {
        LIST;
        printf("%d: %s", linenum++, buf);
        buf[0] = '\0';
        }

[ \t]*  {LIST;}

.       {
        LIST;
        printf("%d:%s\n", linenum+1, buf);
        printf("bad character:'%s'\n",yytext);
        }
%%

int yywrap() {
    return 1;
}

int main(int argc, char *argv[]) {
    yylex();
    dump();
}