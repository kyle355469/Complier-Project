
%{
#define LIST     strcat(buf,yytext)
#define STRLIST  strcat(Strbuf, yytext)   
#define token(s) {LIST; if(debugMode) { printf("<%s>\n",s);}}
#define tokenInteger(t,i) {LIST; if(debugMode) { printf("<%s:%d>\n",t,i);}}
#define tokenReal(t,i) {LIST; if(debugMode) { printf("<%s:%f>\n",t,i);}}
#define tokenString(t,s) {LIST; if(debugMode) { printf("<%s:%s>\n",t,s);}}

#ifndef TABLE_DIF
#define TABLE_DIF
#include "table.h"
#endif
#ifndef YTABH_DIF
#define YTABH_DIF
#include "y.tab.h"
#endif

#define MAX_LINE_LENG 256
int linenum = 1;
extern FILE *out;
char buf[MAX_LINE_LENG];
char Strbuf[MAX_LINE_LENG];
int debugMode = 0;


//{String}  {tokenString("String", yytext)}
%}
Id [a-zA-Z][0-9a-zA-Z]*

%x COMMENT STR

%%
"."     {token("."); return DOT;}
","     {token(","); return COMMA;}
":"     {token(":"); return COLON;}
";"     {token(";"); return SEMICOLON;}
"\("     {token("("); return U_PAREN;}
"\)"     {token(")"); return L_PAREN;}
"["     {token("["); return U_BRACKET;}
"]"     {token("]"); return L_BRACKET;}
"\{"     {token("{"); return U_B_PAREN;}
"\}"     {token("}"); return U_B_PAREN;}
"+"     {token("+"); return PLUS;}
"-"     {token("-"); return MINUS;}
"*"     {token("*"); return TIMES;}
"/"     {token("/"); return DIV;}
"mod"   {token("MOD"); return MOD;}
":="    {token(":="); return GIVEN_EQUAL;}
"<"     {token("<"); return L_T;}
"<="    {token("<="); return EL_T;}    
">="    {token(">="); return EM_T;}
">"     {token(">"); return M_T;}
"="     {token("="); return EQUAL;}
"not="  {token("NOT_EQ"); return NOT_EQ;}
"and"   {token("AND"); return AND;}
"or"    {token("OR"); return OR;}
"not"   {token("NOT"); return NOT;}
begin   {token("BEGIN"); return BBEGIN;}
bool    {token("BOOL"); return BOOL;}
char    {token("CHAR"); return CHAR;}
const   {token("CONST"); return CONST;}
decreasing  {token("DECREASING"); return DECREASING;}
default     {token("DEFAULT"); return DEFAULT;}
do      {token("DO"); return DO;}
else    {token("ELSE"); return ELSE;}
end     {token("END"); return END;}
exit    {token("EXIT"); return T_EXIT;}
false   {token("FALSE"); return T_FALSE;}
for     {token("FOR"); return FOR;}
function    {token("FUNCTION"); return FUNCTION;}
if      {token("IF"); return T_IF;}
int     {token("INT"); return INT;}
loop    {token("LOOP"); return LOOP;}
of      {token("OF"); return OF;}
put     {token("PUT"); return PUT;}
procedure   {token("PROCEDURE"); return PROCEDURE;}
real    {token("REAL"); return REAL;}
result  {token("RESULT"); return RESULT;}
return  {token("RETURN"); return RETURN;}
skip    {token("SKIP"); return SKIP;}
string  {token("STRING"); return STRING;}
then    {token("THEN"); return THEN;}
true    {token("T_TRUE"); return T_TRUE;}
var     {token("VAR"); return VAR;}
when    {token("WHEN"); return WHEN;}
\"      {LIST; Strbuf[0] = '\0'; BEGIN STR; }
<STR>[^\"] {STRLIST;LIST;}
<STR>\"\"    {LIST; strcat(Strbuf, "\"");}
<STR>\"      { tokenString("STRING", Strbuf); BEGIN INITIAL; yylval.input = Strbuf; return STR_CONT;}

"\{\%"   {token("COMMENT"); BEGIN COMMENT;}
<COMMENT>[^\n\%\}]*  {LIST;}
<COMMENT>\n    {
                LIST;
                printf("%d: %s", linenum++, buf);
                buf[0] = '\0';
                }
<COMMENT>"%}"   {LIST; BEGIN INITIAL;}
([0-9]*)  {tokenInteger("INTEGER", atoi(yytext)); yylval.input = yytext; return INT_NUM;}
([1-9][0-9]*|0)(\.[0-9]+)  {tokenString("REAL", yytext); yylval.input = yytext; return REAL_NUM;}
{Id} {
        tokenString("id", yytext);
        char* temp = (char*)malloc(50);
        for(int i = 0; yytext[i] != '\0'; i++){
                temp[i] = yytext[i];
        }
        yylval.input = temp;
        return ID;
}
"%".*     {LIST;}

\n      {
        printf("%d: %s\n", linenum, buf);
        fprintf(out, "/* %d: %s */\n", linenum, buf);
        linenum++;
        buf[0] = '\0';
        }

[ \t]*  {LIST;}

.       {
        LIST;
        // printf("%d:%s\n", linenum+1, buf);
        // printf("bad character:'%s'\n",yytext);
        //exit(-1);
        }
%%

int yywrap() {
    return 1;
}

// int main(int argc, char *argv[]) {
//     yylex();
//     dump();
// }