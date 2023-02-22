#include "./include.h"
#include "./my_blockchain.h"
///////////////////////////
char* my_readline(int fd){
    char c;
    char* string=(char*)malloc(READLINE_READ_SIZE);
    int i=0,j;
    while ((j=read(fd,&c,1)) >= 0){
        if(j==0){
            if((int)strlen(string) > 0)
                return string;
            else
                return NULL;
        }
        if(c=='\n'){
            return string;
        }else{
            if(i < READLINE_READ_SIZE){
                string[i++]=c;
            }
        }
    }
    return NULL;
}
