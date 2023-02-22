#include "./struct.h"
#define READLINE_READ_SIZE 512
void parse_error(int error);
char* Read_str_bufer(int dir, char* str, int* val, int* data, int* fd);
char* my_readline(int fd);
listnode* my_split(char *str, char *str2);
int sorted_(char* str1, char* str2);
void clear_node(char* strt, char* str);
void inverse(char* s);
void to_str(int n, char* s);
int length_node(list**node);
int have_node(list** nodes, int id);
int empty_node(list** nodes);
int node_add(list** node, int id, int val);
int node_dell(list** node);
int key_dell_node(list **node, int val);
void blockremove(listnode **node, char* name);
int is_exit(list** node, char* name );
int removeblock(list **nodes, char* name);
void to_add_block(list** node, listnode** block);
int block_id(list** nodes, char* name , int val);
int add_block(list**nodes, char* name);
void asci_sort(list** node, int val);
void print_node(list**node, int val);
int have_block_in_blist(listnode** block, char* name);
void add_last(listnode**nodes, char* name);
listnode* sort_block(list** file);
void node_sys(list**nodes);
int block_sys(listnode** first, listnode** second);
int sync_sort_flag(list**nodes);
void open_node_write(list* node,char* name);
int my_sort_flag(list** node, listnode* array,char* name);

