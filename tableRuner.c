#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct symbol{
    char* name;             // id
    char* id_type;          // func or what
    int isConst;            // const or not
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
    struct LevelTable* p;
    struct LevelTable* innerLink;
}LT;
LT* pointer;
LT* starter(char*);
LT* createTable(LT* upLevelTable, char* name, Symbol* input_symbol, int n);
LT* deleteTable(LT* nowTable);
void allTableDump(LT* Table);
int lookup(LT* nowTable, char* name);
void insert(LT* nowTable, char* name, char* type, char* value, int isCosnt);
int changeValue(LT* nowTable, char*);
void insert_symbol(LT* nowTable, Symbol input_symbol);
void dump();

int main() {
    
    pointer = starter("main");
    int command = 1;
    while(command != 0){
        printf("0:\texit\n1:\tnew table\n2:\tchange value\n3:\tinsert element\n4:\tdump\n5:\tclear\ninput:");
        scanf("%d", &command);
        if(command == 0){
            break;
        }else if(command == 1){
            char input[50];
            printf("new table name:");
            scanf("%s", input);
            pointer = createTable(pointer, input, NULL, 0);
        }else if(command == 2){
            char input_name[50];
            printf("element name:");
            scanf("%s", input_name);
            int note = changeValue(pointer, input_name);
            if(note == -1){
                printf("no symbol exist\n");
            }else if(note == -2){
                printf("symbol unchangable (const type)\n");
            }else{
                printf("changable\n");
            }
        }else if(command == 3){
            char input_name[50], input_type[50], input_value[50];
            int isConst;
            printf("new element name:");
            scanf("%s", input_name);
            printf("new element type:");
            scanf("%s", input_type);
            printf("new element value:");
            scanf("%s", input_value);
            printf("is const? (1/0):");
            scanf("%d", &isConst);
            insert(pointer, input_name, input_type, input_value, isConst);
        }else if(command == 4){
            allTableDump(pointer);
        }else if(command == 5){
            system("clear");
        }else{
            printf("unrecognized command\n");
        }
    }
}


LT* starter(char* name){
    LT* st = (LT*)malloc(sizeof(LT));
    st->t.tableSize = 0;
    st->p = NULL;
    st->innerLink = NULL;
    char* temp = (char*)malloc(50);
    for(int j = 0; name[j] != '\0'; j++){
        temp[j] = name[j];
    }
    st->tableName = temp;
    return st;
}

LT* createTable(LT* upLevelTable, char* name, Symbol* input_symbol, int n){
    LT* inputTable = (LT*)malloc(sizeof(LT));
    LT* insideTable = (LT*)malloc(sizeof(LT));
    char* temp = (char*)malloc(50);
    for(int j = 0; name[j] != '\0'; j++){
        temp[j] = name[j];
    }
    inputTable->tableName = temp;
    insideTable->tableName = temp;
    inputTable->innerLink = insideTable;
    insideTable->innerLink = inputTable;
    inputTable->t.tableSize = 0;
    insideTable->t.tableSize = 0;
    inputTable->p = upLevelTable;
    for(int i = 0; i < n; i++){
        insert_symbol(inputTable, input_symbol[i]);
    }
    return inputTable;
}

LT* deleteTable(){
    LT* delT = pointer;
    if(delT->innerLink != NULL){
        free(delT->innerLink);
    }
    pointer = pointer->p;
    free(delT);
    return pointer;
}
// 看能不能 extern 改掉
int lookup(LT* nowTable, char* name){
    printf("inside table %s doing compare section\n", nowTable->tableName);
    Table t = nowTable->t;
    for(int i = 0; i < t.tableSize; i++){
        printf("compare %d \"%s\" & \"%s\"\n", i, t.id[i].name, name);
        if(!strcmp(t.id[i].name, name)){
            return i;
        }
    }
    return -1;
}

// insert symbol into the given table
void insert(LT* nowTable, char* name, char* type, char* value, int isConst){
    char* temp_name = (char*)malloc(50);
    for(int j = 0; name[j] != '\0'; j++){
        temp_name[j] = name[j];
    }
    int index = lookup(nowTable, name);
    if(index == -1){
        char* temp_type = (char*)malloc(50);
        for(int j = 0; type[j] != '\0'; j++){
            temp_type[j] = type[j];
        }
        nowTable->t.id[nowTable->t.tableSize].id_type = temp_type;
        nowTable->t.id[nowTable->t.tableSize].isConst = isConst;
        nowTable->t.id[nowTable->t.tableSize].name = temp_name; 
        nowTable->t.tableSize++;
    }else{
        printf("element exist, position:%d", index);
    }
}

// symbol pointer 只會有一個 structure element, createTable 會控制
void insert_symbol(LT* nowTable, Symbol input_symbol){
    int index = lookup(nowTable, input_symbol.name);
    if(index == -1){
        nowTable->t.id[nowTable->t.tableSize] = input_symbol;
        nowTable->t.tableSize++;
    }else{
         printf("element exist, position:%d", index);
    }
}

// check if the symbol's value is changeble
int changeValue(LT* nowTable, char* name){
    int index = lookup(nowTable, name);
    if(index == -1){
        if (nowTable->p == NULL){
            return -1;  // represant no symbol
        }
        return changeValue(nowTable->p, name); 
    }else{
        if (nowTable->t.id[index].isConst == 1){
            return -2;  // represant is constant
        }
    }
    return 1;
}

void allTableDump(LT* table){
    LT* temp = (LT*)malloc(sizeof(LT));
    temp = table;
    while(temp != NULL){
        printf("-------- table %s --------\n", temp->tableName);
        printf("no.\tname\ttype\tisConst\n");
        for(int i = 0; i < temp->t.tableSize; i++){
            printf("%d->\t%s\t%s\t", i, temp->t.id[i].name, temp->t.id[i].id_type);
            if(temp->t.id[i].isConst == 1){
                printf("TRUE\n");
            }else{
                printf("FALSE\n");
            }
        }
        if(temp->innerLink != NULL){
            for(int i = 0; i < temp->innerLink->t.tableSize; i++){
                printf("%s\t%s\t", temp->innerLink->t.id[i].name, temp->innerLink->t.id[i].id_type);
                if(temp->innerLink->t.id[i].isConst == 1){
                    printf("TRUE\n");
                }else{
                    printf("FALSE\n");
                }
            }
        }
        temp = temp->p;
    }
}