#include "table.h"

const char* type_name[] = {" ","int", "real", "bool", "string", "non"};
extern int NMode;
extern FILE *out;
int totalIndexCount = 0;
LT* starter(char* name){
    LT* st = (LT*)malloc(sizeof(LT));
    st->startLine = 0;
    st->t.tableSize = 0;
    st->p = NULL;
    st->l = NULL;
    st->innerLink = NULL;
    st->returnType.type = non;
    char* temp = (char*)malloc(50);
    for(int j = 0; name[j] != '\0'; j++){
        temp[j] = name[j];
    }
    st->tableName = temp;
    
    return st;
}

LT* createTable(LT* upLevelTable, LT* tablePosition, char* name, int stLine){
    LT* inputTable = (LT*)malloc(sizeof(LT));
    LT* insideTable = (LT*)malloc(sizeof(LT));
    char* temp = (char*)malloc(50);
    for(int j = 0; name[j] != '\0'; j++){
        temp[j] = name[j];
    }
    inputTable->startLine = stLine;
    insideTable->startLine = stLine;
    inputTable->tableName = temp;
    insideTable->tableName = temp;
    inputTable->innerLink = insideTable;
    insideTable->innerLink = inputTable;
    inputTable->t.tableSize = 0;
    insideTable->t.tableSize = 0;
    inputTable->p = tablePosition;
    inputTable->l = upLevelTable;
    inputTable->returnType.type = non;
    insideTable->returnType.type = non;
    return inputTable;
}

// LT* deleteTable(){
//     LT* delT = pointer;
//     if(delT->innerLink != NULL){
//         free(delT->innerLink);
//     }
//     pointer = pointer->p;
//     free(delT);
//     return pointer;
// }
// 看能不能 extern 改掉
int lookup(LT* nowTable, char* name){
    //printf("inside table %s doing compare section\n", nowTable->tableName);
    Table t = nowTable->t;
    for(int i = 0; i < t.tableSize; i++){
        //printf("compare %d \"%s\" & \"%s\"\n", i, t.id[i].name, name);
        if(!strcmp(t.id[i].name, name)){
            return t.id[i].index;
        }
    }
    return -1;
}

typeDef getFunctionInputType(LT* nowTable, int index){
    return nowTable->innerLink->t.id[index].type;
}

typeDef typeLookUp(LT* nowTable, char* name, int arrayIndex){
    //printf("inside table %s doing compare section\n", nowTable->tableName);
    Table t = nowTable->t;
    if(arrayIndex != -1){
        for(int i = 0; i < t.tableSize; i++){
            char* temp;
            sprintf(temp, "%s:%d", name, arrayIndex);
            //printf("compare %d \"%s\" & \"%s\"\n", i, temp, name);
            if(!strcmp(temp, name)){
                return t.id[i].type;
            }
        }
    }else{
        for(int i = 0; i < t.tableSize; i++){
            //printf("compare %d \"%s\" & \"%s\"\n", i, t.id[i].name, name);
            if(!strcmp(t.id[i].name, name)){
                return t.id[i].type;
            }
        }
    }
    if(nowTable->p != NULL){
        return typeLookUp(nowTable->p, name, arrayIndex);
    }else{
        typeDef a;
        a.type = non;
        return a;
    }
}

// insert symbol into the given table
void insert(LT* nowTable, char* name, typeDef type, int isConst, int arrayIndex/*, char* value*/){
    char* temp_name = (char*)malloc(50);
    for(int j = 0; name[j] != '\0'; j++){
        temp_name[j] = name[j];
    }
    int index = lookup(nowTable, name);
    if(index == -1){
        // char* temp_value = (char*)malloc(50);
        // for(int i = 0; value[i] != '\0'; i++){
        //     temp_value[i] = value[i];
        // }
        // nowTable->t.id[nowTable->t.tableSize].value = temp_value;
        nowTable->t.id[nowTable->t.tableSize].isArray = 0;
        nowTable->t.id[nowTable->t.tableSize].arrayIndex = arrayIndex;
        nowTable->t.id[nowTable->t.tableSize].type = type;
        nowTable->t.id[nowTable->t.tableSize].isConst = isConst;
        nowTable->t.id[nowTable->t.tableSize].name = temp_name; 
        if (isConst == 0 && strcmp(nowTable->tableName, "main")){
            nowTable->t.id[nowTable->t.tableSize].index = totalIndexCount++;
        }else{
            nowTable->t.id[nowTable->t.tableSize].index = -8;
        }
        nowTable->t.tableSize++;
        printf("\t-note: insertion success, index:%d, type:%s\n", nowTable->t.tableSize - 1, type_name[type.type]);
    }else{
        printf("\t--warning: element exist, position:%d\n", index);
    }
}

// symbol pointer 只會有一個 structure element, createTable 會控制
void insert_symbol(LT* nowTable, Symbol input_symbol, int Control){
    if(Control == 1){
        int index = lookup(nowTable->innerLink, input_symbol.name);
        if(index == -1){
            nowTable->innerLink->t.id[nowTable->innerLink->t.tableSize] = input_symbol;
            if (input_symbol.isConst == 0){
                nowTable->innerLink->t.id[nowTable->innerLink->t.tableSize].index = totalIndexCount++;
            }else{
                nowTable->innerLink->t.id[nowTable->innerLink->t.tableSize].index = -8;
            }
            nowTable->innerLink->t.id[nowTable->innerLink->t.tableSize].index = totalIndexCount++;
            nowTable->innerLink->t.tableSize++;
        }else{
            printf("\t--warning: element exist, position:%d\n", index);
        }
    }else{
        int index = lookup(nowTable, input_symbol.name);
        if(index == -1){
            nowTable->t.id[nowTable->t.tableSize] = input_symbol;
            if (input_symbol.isConst == 0){
                nowTable->t.id[nowTable->t.tableSize].index = totalIndexCount++;    
            }else{
                nowTable->t.id[nowTable->t.tableSize].index = -8;
            }
            
            nowTable->t.tableSize++;
        }else{
            printf("\t--warning: element exist, position:%d\n", index);
        }
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
        if(temp->returnType.type != non){
            printf("-------- table %s --------", temp->tableName);
            printf("\treturn type:%s", type_name[temp->returnType.type]);
        }else{
             printf("-------- table %s --------", temp->tableName);
        }
        printf("\tsatrt line:%d\t------------------\n", temp->startLine);
        printf("no.\t\tname\t\ttype\tisConst\tvalue\tisArray\tupper\tlower\n");
        //printf("%d\n", temp->t.tableSize);
        for(int i = 0; i < temp->t.tableSize; i++){
            if(strlen(temp->t.id[i].name) > 7){
                printf("%d->\t\t%s\t%s\t", temp->t.id[i].index, temp->t.id[i].name, type_name[temp->t.id[i].type.type]);
            }else{
                printf("%d->\t\t%s\t\t%s\t", temp->t.id[i].index, temp->t.id[i].name, type_name[temp->t.id[i].type.type]);
            }
            
            if(temp->t.id[i].isConst == 1){
                printf("TRUE\t%s\t", temp->t.id[i].value); 
            }else{
                printf("FALSE\tX\t");
            }
            if(temp->t.id[i].isArray == 1){
                printf("TRUE\t%d\t%d\n", temp->t.id[i].arrayLowerBound, temp->t.id[i].arrayUpperBound); 

            }else{
                printf("FALSE\tX\tX\n");
            }
        }
        if(temp->innerLink != NULL){
            //printf("%d\n", temp->innerLink->t.tableSize);
            for(int i = 0; i < temp->innerLink->t.tableSize; i++){
                if(strlen(temp->innerLink->t.id[i].name) > 7){
                    printf("%s%d->\t\t%s\t%s\t", "ref:",temp->t.id[i].index, temp->innerLink->t.id[i].name, type_name[temp->innerLink->t.id[i].type.type]);
                }else{
                    printf("%s%d->\t\t%s\t\t%s\t", "ref:",temp->t.id[i].index, temp->innerLink->t.id[i].name, type_name[temp->innerLink->t.id[i].type.type]);
                }
                if(temp->innerLink->t.id[i].isConst == 1){
                    printf("TRUE\t%s\t", temp->t.id[i].value); 
                }else{
                    printf("FALSE\tX\t");
                }
                if(temp->innerLink->t.id[i].isArray == 1){
                    printf("TRUE\t%d\t%d\n", temp->innerLink->t.id[i].arrayLowerBound, temp->innerLink->t.id[i].arrayUpperBound); 

                }else{
                    printf("FALSE\tX\tX\n");
                }
            }
        }
        temp = temp->p;
    }
    free(temp);
}

void setReturnType(LT* nowTable, typeDef type_num){
    nowTable->returnType = type_num;
    nowTable->innerLink->returnType = type_num;
}

typeDef typeCalculateCheck(typeDef first, typeDef second){
    switch(first.type){
        case int_type:
            if(second.type == int_type || second.type == bool_type){
                typeDef a;
                a.type = int_type;
                return a;
            }else if(second.type == real_type){
                typeDef a;
                a.type = real_type;
                return a;
            }else{
                typeDef a;
                a.type = non;
                return a;
            }
            break;
        case real_type:
            if(second.type == int_type || second.type == bool_type || second.type == real_type){
                typeDef a;
                a.type = real_type;
                return a;
            }
            break;
        case bool_type:
            if(second.type == int_type){
                typeDef a;
                a.type = int_type;
                return a;
            }else if(second.type == real_type){
                typeDef a;
                a.type = real_type;
                return a;
            }else if(second.type == bool_type){
                typeDef a;
                a.type = bool_type;
                return a;
            }else{
                typeDef a;
                a.type = non;
                return a;
            }
            break;
        case str_type:
            if(second.type == str_type){
                typeDef a;
                a.type = str_type;
                return a;
            }else{
                typeDef a;
                a.type = non;
                return a;
            }
            break;
        case non:
        default:
            break;
    }
    typeDef a;
    a.type = non;
    return a;
}

typeDef tableReturnType(LT* header, char* tableName){
    if(!strcmp(header->tableName, tableName)){
        return header->returnType;
    }else if(header->p != NULL){
        return tableReturnType(header->p, tableName);
    }else{
        typeDef a;
        a.type = non;
        return a;
    }
}

LT* findTable(LT* tail, char* tableName){
    if(tail != NULL){
        int i = 0;
        //printf("now table: %s\n", tail->tableName);
        for(i = 0; tableName[i] != '\0' || tail->tableName[i] != '\0'; i++){
            //printf("now comp: %c & %c \n", tableName[i], tail->tableName[i]);
            if(tableName[i] != tail->tableName[i]){
                //printf("diff: %c & %c \n", tableName[i], tail->tableName[i]);
                if(tail->p != NULL){
                    return findTable(tail->p, tableName);
                }
                return NULL;
            }
        }
        printf("match\n");
        return tail;
        
    }
    return NULL;
}

typeDef typeCheck(char* input){
    if (!strcmp(input, "true") || !strcmp(input, "false")){
        typeDef a;
        a.type = bool_type;
        return a;
    }
    for(int i = 0; input[i] != '\0'; i++){
        if((input[i] < '0' || input[i] > '9') && input[i] != '.'){
            typeDef a;
            a.type = str_type;
            return a;
        }else if(input[i] == '.' && i != 0){
            typeDef a;
            a.type = real_type;
            return a;
        }
    }
    typeDef a;
    a.type = int_type;
    return a;
}

char* intToChar(int input){
    int a[100];
    int i;
    for(i = 0; input != 0; i++){
        a[i] = input % 10;
        input /= 10;
    }
    char* output = (char*)malloc(i);
    for(int j = 0; j < i; j++){
        output[j] = a[i - j - 1] + '0';
    }
    return output;
}

// void arrayInsertion(LT* nowTable, char* name, typeDef type, int head, int tail){
//     char* temp_name = (char*)malloc(50);
//     for(int j = 0; name[j] != '\0'; j++){
//         temp_name[j] = name[j];
//     }
//     int index = lookup(nowTable, name);
//     if(index == -1){
//         // char* temp_value = (char*)malloc(50);
//         // for(int i = 0; value[i] != '\0'; i++){
//         //     temp_value[i] = value[i];
//         // }
//         // nowTable->t.id[nowTable->t.tableSize].value = temp_value;
//         nowTable->t.id[nowTable->t.tableSize].arrayIndex = 1;
//         nowTable->t.id[nowTable->t.tableSize].type = type;
//         nowTable->t.id[nowTable->t.tableSize].isConst = 0;
//         nowTable->t.id[nowTable->t.tableSize].index = totalIndexCount++; 
//         nowTable->t.id[nowTable->t.tableSize].name = temp_name; 
//         nowTable->t.id[nowTable->t.tableSize].isArray = 1;
//         nowTable->t.id[nowTable->t.tableSize].arrayUpperBound = tail;
//         nowTable->t.id[nowTable->t.tableSize].arrayLowerBound = head;
//         nowTable->t.tableSize++;
//         printf("\t-note: insertion success, index:%d\n", nowTable->t.tableSize - 1);
//     }else{
//         printf("\t--warning: element exist, position:%d\n", index);
//     }
// }

int isInTheRange(LT* nowTable, char* name, int index){
    //printf("a\n" );
    int a = lookup(nowTable, name);
    if(a != -1 && !nowTable->t.id[a].isArray){
        printf("\t--warning: %s is not an array\n", nowTable->t.id[a].name);
    }
    //printf("%s %d %d\n", nowTable->t.id[a].name,nowTable->t.id[a].arrayLowerBound, nowTable->t.id[a].arrayUpperBound);
    if (a != -1 && nowTable->t.id[a].isArray){
        
        if(nowTable->t.id[a].arrayLowerBound <= index && nowTable->t.id[a].arrayUpperBound >= index){
            return 1;
        }
        return 0;
    }
    if(nowTable->l != NULL){
        return isInTheRange(nowTable->l, name, index);
    }
    return 0;
}


void constInsertion(LT* nowTable, char* name, typeDef type, char* value){
    char* temp_name = (char*)malloc(50);
    for(int j = 0; name[j] != '\0'; j++){
        temp_name[j] = name[j];
    }
    char* temp_value = (char*)malloc(50);
    for(int j = 0; value[j] != '\0'; j++){
        temp_value[j] = value[j];
    }
    int index = lookup(nowTable, name);
    if(index == -1){
        // char* temp_value = (char*)malloc(50);
        // for(int i = 0; value[i] != '\0'; i++){
        //     temp_value[i] = value[i];
        // }
        // nowTable->t.id[nowTable->t.tableSize].value = temp_value;
        nowTable->t.id[nowTable->t.tableSize].arrayIndex = 1;
        nowTable->t.id[nowTable->t.tableSize].type = type;
        nowTable->t.id[nowTable->t.tableSize].index = -8;
        nowTable->t.id[nowTable->t.tableSize].isConst = 1;
        nowTable->t.id[nowTable->t.tableSize].name = temp_name; 
        nowTable->t.id[nowTable->t.tableSize].isArray = 0;
        nowTable->t.id[nowTable->t.tableSize].value = temp_value;
        nowTable->t.tableSize++;
         printf("\t-note: insertion success, index:%d, type:%s\n", nowTable->t.tableSize - 1, type_name[type.type]);
    }else{
        printf("\t--warning: element exist, position:%d\n", index);
    }
}

int allLookUp(LT* nowTable, char* name){
    
    if(nowTable != NULL){
        int a = lookup(nowTable, name);
        if(a == -1){
            return allLookUp(nowTable->l, name);
        }else{
            //printf("%s\n", nowTable->tableName);
            return a;
        }
    }
    return -1;
}

void printTab(int count){
    for(int i = 0; i < count; i++){
        fprintf(out, "\t");
    }
}

Symbol getNode(LT* nowTable, char* name){
    if(nowTable != NULL){
        Table t = nowTable->t;
        for(int i = 0; i < t.tableSize; i++){
            //printf("compare %d \"%s\" & \"%s\"\n", i, t.id[i].name, name);
            if(!strcmp(t.id[i].name, name)){
                return t.id[i];
            }
        }
        if(nowTable->innerLink != NULL){
            for(int i = 0; i < nowTable->innerLink->t.tableSize; i++){
                //printf("compare %d \"%s\" & \"%s\"\n", i, t.id[i].name, name);
                if(!strcmp(nowTable->innerLink->t.id[i].name, name)){
                    return nowTable->innerLink->t.id[i];
                }
            }
        }
        
        return getNode(nowTable->p, name);
    }
    Symbol a;
    a.index = -100;
    return a;
}

LT* getNodesScope(LT* nowTable, char* name){
    if(nowTable != NULL){
        Table t = nowTable->t;
        for(int i = 0; i < t.tableSize; i++){
            //printf("compare %d \"%s\" & \"%s\"\n", i, t.id[i].name, name);
            if(!strcmp(t.id[i].name, name)){
                return nowTable;
            }
        }
        if(nowTable->innerLink != NULL){
            for(int i = 0; i < nowTable->innerLink->t.tableSize; i++){
                //printf("compare %d \"%s\" & \"%s\"\n", i, t.id[i].name, name);
                if(!strcmp(nowTable->innerLink->t.id[i].name, name)){
                    return nowTable;
                }
            }
        }
        
        return getNodesScope(nowTable->p, name);
    }
    LT* a;
    a->tableName = "notExist";
    return a;
}