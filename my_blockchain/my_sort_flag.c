#include "./my_blockchain.h"
#include "./include.h"
int my_sort_flag(list** node, listnode* array,char* name){
    int is=0, rm=0, block=0, flag=0;
         int i = 0;
     if (array->size> 2 && array->array[2]!=0) {
        if(sorted_(array->array[i], "add"))
            is = 1;
        else if(sorted_(array->array[i], "rm"))
            rm = 1;
        else {
            parse_error(6);
            return 0;
        }
        if((is || rm) && sorted_(array->array[i+1], "node"))
            block = 1;
        else if((rm || is) && sorted_(array->array[i+1], "block") && array->size>=3)
            flag = 1;
        else {
            parse_error(6);
            return 0;
        }
    }
        else  if(array->size==1 || array->size==2){
        if(sorted_(array->array[i], "quit")){
            open_node_write(*node,name);
             exit(0);
        } else if(sorted_(array->array[i], "ls") && sorted_(array->array[1], "-l")){
            print_node(node, 1);
            return 0;
        } else if(sorted_(array->array[i], "ls")) {
           
            print_node(node, 0);
            return 0;
        } else if(sorted_(array->array[i], "sync")){
            node_sys(node);
            printf("OK\n");
            return 0;
        } else{
                parse_error(6);
            return 0;
        }
    }  
    else {
            parse_error(6);
        return 0;
    }
    int is_inside = 0;
    for(int i=2; i < array->size; i++){

        if(is){
            if(flag){
                if(array->size < 4){
                    parse_error(6);
                    break;
                }
                if(sorted_(array->array[3], "*")) {
                    if(add_block(node, array->array[2]))
                        printf("OK\n");
                    break;
                }else{
                    if(i == 2) continue;
                    if(block_id(node, array->array[2], atoi(array->array[i])) && !is_inside){
                        printf("OK\n");
                        is_inside = 1;
                    }
                    
                }
            }else if(block) {
                if(array->array[i] != 0)
                if(node_add(node, atoi(array->array[i]), 0) && !is_inside){
                    printf("OK\n");
                    break;
                }
            }
        } else if(rm) {
            if(block){
                if(sorted_(array->array[2], "*")){
                    if(node_dell(node)) 
                        printf("OK\n");
                    break;
                } else {
                    if(array->array[i]!=0)
                    if(key_dell_node(node, atoi(array->array[i])) && !is_inside){
                        printf("OK\n");
                        is_inside = 1;
                    }
                }
            }else if(flag){
                if(array->array[i] != 0)
                    if(removeblock(node, array->array[i]) && !is_inside){
                        printf("OK\n");
                        is_inside = 0;
                    }
            }
        }
    }
    return 0;
}
