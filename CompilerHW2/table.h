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
enum Type{
        int_type = 1,
        real_type,
        bool_type,
        str_type,
        non
};
typedef struct TypeDef{
    enum Type type;
}typeDef;


typedef struct symbol{
    char* name;             // id
    //char* id_type;          // func or what
    typeDef type;
    int isConst;            // const or not
    int arrayIndex;
    char* value;
    int isArray;
    int arrayUpperBound;
    int arrayLowerBound;
    // int int_value;
    // double real_value;
    // char* string_value;
    // int boolen_value;
}Symbol;

typedef struct table
{
    Symbol id[256];
    int tableSize;
}Table;

typedef struct LevelTable{
    Table t;
    char* tableName;
    int startLine;
    typeDef returnType;
    struct LevelTable* p;           // linker
    struct LevelTable* l;           // upperTable
    struct LevelTable* innerLink;
}LT;



LT* starter(char*);
LT* createTable(LT* upLevelTable, LT* tablePosition, char* name, int stLine);
void setReturnType(LT* nowTable, typeDef type_num);
// LT* deleteTable(LT* nowTable);
void allTableDump(LT* Table);
int lookup(LT* nowTable, char* name);
typeDef getFunctionInputType(LT* nowTable, int index);
typeDef typeLookUp(LT* nowTable, char* name, int arrayIndex);
void insert(LT* nowTable, char* name, typeDef type, int isCosnt, int arrayIndex/*, char* value*/);
int changeValue(LT* nowTable, char*);
void insert_symbol(LT* nowTable, Symbol input_symbol, int Control);
void dump();
typeDef typeCalculateCheck(typeDef first, typeDef second);
typeDef tableReturnType(LT* header, char* tableName);
typeDef getIdentifierType(LT* header, char* id_name);
LT* findTable(LT* tail, char* tableName);
typeDef typeCheck(char* input);
char* intToChar(int input);
void arrayInsertion(LT* nowTable, char* name, typeDef type, int head, int tail);
int isInTheRange(LT* nowTable, char* name, int index);
void constInsertion(LT* nowTable, char* name, typeDef type, char* value);
int allLookUp(LT* nowTable, char* name);