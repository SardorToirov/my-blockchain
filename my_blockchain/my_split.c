#include "./include.h"
#include "./my_blockchain.h"
////////////////////////////
listnode* my_split(char *str, char *str2){
    listnode* node = (listnode*) malloc(sizeof(listnode));
    int d = 1;
    for (int i = 0; str[i]; i++){
        if (str[i] == str2[0]) {
            d++;
        }
    }
    if (strcmp(str, "") == 0 && strcmp(str2, "") == 0) {
        node->size = 0;
        node->array = malloc(1);
        node->array[0] = "";
        return node;
    }else{
        node->size = d;
        char* res =  malloc(strlen(str)+1);
        node->array = malloc(d);
        res = strtok(str, str2);
        int p = 0;
        while (res != 0) {
            int len = strlen(res);
            char* cop = malloc(len + 2);
            strcpy(cop, res);
            node->array[p++] = cop;
            res = strtok(res + len + 1, str2);
        }
        return node;
    }
}
