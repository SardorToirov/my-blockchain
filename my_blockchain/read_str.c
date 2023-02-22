#include "./include.h"
#include "./my_blockchain.h"
////////////////////////////
char* Read_str_bufer(int num, char* str, int* val, int* data, int* fd){
    int B = 0;
    while(!B){
        for( *val = 0; val < data; val++ ){
            if (str[*val] == '\n'){
                B = 1;
                break;
            }
        }
            if(B == 1)
            break;
        *fd = read(num, &str[*val], READLINE_READ_SIZE);
        if ( *fd > 0 )
            *data += *fd;

        else
            B = 1;
    }

    return str;
}
