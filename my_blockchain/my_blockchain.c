/*
&&&&&&&&&&&&& SARDOR &&&&&&&&&&&&
*/
#include "./include.h"
#include "./my_blockchain.h"

//  code you use with make ./my_blockchain block

void parse_error(int error){

        if(error == 1)
        printf("Node doesn't exist\n");
        else if(error == 2)
        printf("Node id cannot be '0'\n");
        else if(error == 3)
        printf("This node already exists\n");
        else if(error == 4)
        printf("Block doesn't exist\n");
        else if(error == 5)
        printf("This block already exists\n");

}

int sorted_(char* str1, char*str2) {
    if(str1==0 && str2==0)
        return 1;
    if(str1 == 0)
        return 0;
    if(strlen(str1) != strlen(str2))
        return 0;
    for(int i=0; str2[i] !='\0'; i++){
        if(str1[i] == '\0') return 0;
        if(str1[i] != str2[i]) return 0;
    }
    return 1;
}

void clear_node(char* strt, char* str){

    int i = 0,d;
     while(str[i] == 32){
        i++;
    }
    for(d = 0;str[i]; i++){
      if(str[i]== 32 && str[i-1]== 32 ){
          continue;
      }
      strt[d] = str[i];
      d++;
      
    }
    strt[d] = '\0';
}

// revers
void inverse(char* str) {
   
     char c;
     for (int i = 0,j = strlen(str)-1; i<j; i++, j--){
         c = str[i];
         str[i] = str[j];
         str[j] = c;
     }
 }
 // integer to str
void to_str(int num, char* str) {
    char* place = malloc(100);
    place = str;
    int i, sign;
 
    if ((sign = num) < 0)  
        num = -num;          
    i = 0;
    do {       
        place[i++] = num % 10 + '0';   
    } while ((num /= 10) > 0);     
    if (sign < 0)
        place[i++] = '-';
    place[i] = '\0';
    inverse(place);
 }

int length_node(list**node) {
    int i = 0;
    if(*node == NULL) return 0;
    list* temp = *node;
    while(temp != NULL) {
        temp = temp->next;
        i++;
    }
    return i;
}

int have_node(list** head, int id) {
    list* node = *head;
    while (node != NULL) {
        if(node->id == id)
            return 1;
        node = node->next;
    }
    return 0;
}

int empty_node(list** nodes) {
    list* node = *nodes;
    if(node->blocklist == NULL)
        return 1;
    return 0;
}

int node_add(list** node, int id, int val) {
    if(id == 0){
        if(!val)
        parse_error(2);
 
        return 0;
    }
    if(have_node(node, id)){
         parse_error(3);
   
        return 0;
    }
    list* new_node = (list*)malloc(sizeof(list));
    if((new_node)) {
        new_node->id = id;
        new_node->blocklist = NULL;
        new_node->next = NULL;
        if(*node == NULL) {
            *node = new_node;
            return 1;
        }
        list *last = *node;
        while(last->next != NULL) {
            last = last->next;
        }
        last->next = new_node;
        return 1;
    }
      printf("\n");
    return 0;
}

int node_dell(list** node){
   list* len = *node;
   if(len == NULL){
       return 1;
   }
   list* next ;
   while (len != NULL) {
       next = len->next;
       free(len);
       len = next;
   }
   *node = NULL;
   return 1;
}

int key_dell_node(list **node, int key) {
    if(!have_node(node, key)) {
        parse_error(1);
        return 0;
    }
    list *temp, *temp2, *check = *node;
    if (*node != 0 && check->id == key) {
        temp = *node;
        *node = check->next;
        free(temp);
        return 1;
    }
    temp = 0;
    temp2  = *node;
    while (temp2 != NULL) {
        if (temp2->id == key) {
            if (temp != NULL) 
                temp->next = temp2->next;
            free(temp2);
            return 1;
        } 

        temp = temp2;
        temp2 = temp2->next;
    }
    return 0;
}


void blockremove(listnode **node, char* name) {
    listnode *temp =  NULL;
    listnode *new_node = NULL;

    if(sorted_((*node)->data ,name)) {
    
        temp = *node;
        *node = (*node)->next;
        free(temp);
        return;
    }

    temp = *node;

    if(temp->next) {
        new_node = temp->next;
        temp->next = new_node->next;
        free(new_node);
    } else {
        parse_error(4);
    }
}
// is block exist in node
int is_exit(list** node, char* name ) {
    list* new_node = *node;
    listnode *temp = new_node->blocklist;
    while (temp != NULL) {
        if(sorted_(temp->data, name))
            return 1;
        temp = temp->next;
    }
    return 0;
}

int removeblock(list **nodes, char* name) {
    list *node = *nodes;
    listnode* temp = malloc(sizeof(listnode));
    temp->data = name;
    int i = 0;
    while(node != NULL) {
        listnode** new_node = &node->blocklist;
        if(is_exit(&node, name)){
            blockremove(new_node, name);
            i = 1;
        }
        node = node->next;
    }
    if(!i){
        parse_error(4);
        return 0;
    }
    return 1;
}

void to_add_block(list** node, listnode** block) {
    list* temp = *node;
    listnode *second = temp->blocklist;
    if(second == NULL){
        temp->blocklist = *block;
    } else {
        listnode* new_node = second;
        while(new_node->next != NULL) {
            new_node = new_node->next;
        }
        new_node->next = *block;
        temp->blocklist = second;
    }
}
int block_id(list** nodes, char* name , int val) {
 if(!have_node(nodes, val)) {
       parse_error(1);
        return 0;
    }
    listnode* new;
    if((new = (listnode*)malloc(sizeof(listnode)))) {
        new->data = name;
        new->size = strlen(name);
        new->next = 0;
        list *node = *nodes;
        while (node != NULL) {
            if (node->id == val) {
                if(is_exit(&node, name)) {
                    parse_error(5);
                    return 0;
                }
                to_add_block(&node, &new);
            
                return 1;
            }
            node = node->next;
        }
        return 1;
    }
      printf("\n");
    return 0;
}
int add_block(list**nodes, char* name) {
    //printf("---%s",name);
    listnode* new = malloc(sizeof(listnode));
    new->data = malloc(strlen(name)+1);
    new->data = name;
    new->next = 0;
    list *node = *nodes;
    int i=0;
    while(node) {
        if(!is_exit(&node, name)) {
            block_id(&node, name, node->id);
            i++;
        }
        node = node->next;
    }
    if(i > 0)
        return 1;
      printf("\n");
    return 0;
}

void asci_sort(list** node, int val) {
   // putchar('\n');
   
    list* temp = *node;
    if(temp->blocklist)
        putchar(' ');
    while (temp != NULL) {
        if(temp->id == val) {
            listnode* temp2 = temp->blocklist;
            while(temp2 != NULL) {
                if(temp2->data == NULL) break;
                    printf("%s", temp2->data);
                if(temp2->next!=NULL)
                    printf(", ");
                temp2 = temp2->next;
            }
            printf("\n");
            break;
        }
        temp = temp->next;
       
    }
}

void print_node(list**node, int val) {
    list* temp = *node;
    if(temp == NULL) printf("Empty\n");
    
    while(temp != NULL) {
            if(val){   
               printf("%d:", temp->id);
               asci_sort(&temp, temp->id);
            } 
            else
                printf("%d\n", temp->id);
        temp = temp->next;
    }
}
int have_block_in_blist(listnode** block, char* name){
    listnode* temp = *block;
    if(*block == NULL) return 0;
    while (temp!=NULL){
        if(sorted_(temp->data, name)) 
            return 1;
        temp = temp->next;
    }
    return 0;
}

void add_last(listnode**nodes, char* name){
    listnode *node =(listnode*)malloc(sizeof(listnode));
    node->data = name;
    node->next = NULL;
    if(*nodes == NULL)
         *nodes = node;
    else {
        listnode *temp = *nodes;
        while(temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = node;
    }
}

listnode* sort_block(list** file){
    list* node = *file;
    listnode* temp = NULL;
    while(node != NULL) {
        listnode*block = node->blocklist;
        while(block != NULL) {
            if(!have_block_in_blist(&temp, block->data) && block->data) {
                add_last(&temp, block->data);
            }
            block = block->next;
        } 
        node = node->next;
    }
    return temp;
}


void node_sys(list**nodes){
    list* node = *nodes;
    while(node) {
        listnode* sync_block = sort_block(nodes);
        free(node->blocklist);
        node->blocklist = sync_block;
        node = node->next;
    }
}
int block_sys(listnode** first, listnode** second) {
    listnode* new_node = *first;
    listnode* temp2 = *second;
    if(*first==NULL && *second==NULL) return 1;
    if((*first==NULL && *second!=NULL)||(*first!=NULL && *second==NULL))
        return 0;
    while(new_node) {
        if(temp2 == NULL)
            return 0;
        if(!sorted_(new_node->data,temp2->data))
            return 0;
        new_node = new_node->next;
        temp2 = temp2->next;
    }
    if(temp2)
        return 0;
    return 1;
}

int sync_sort_flag(list** node) {
    if(*node == NULL) return 1;
    list* temp = *node;
    
    int i = 0;
    while(temp->next) {
        listnode* first = temp->blocklist;
        listnode* second = temp->next->blocklist;
        if(!block_sys(&first, &second))
            i++;
        temp = temp->next;
    }
    return (!i) ? 1 : 0;
}

void open_node_write(list* node,char* name){
    int dir = open(name, O_WRONLY|O_CREAT|O_TRUNC, 0644);

    list* new_node = node;
    char aray[1012];
    int i=0;    
    while(new_node!=NULL){
        char* id = malloc(10);
        to_str(new_node->id, id);
        strcat(aray, id);
        listnode* temp= new_node->blocklist;
        while(temp) {
            strcat(aray, " ");
            strcat(aray, temp->data);
            temp = temp->next;
        }
        if(new_node->next!=NULL)
            strcat(aray, "\n");
        i++;
        new_node = new_node->next;
        
    }
    if(write(dir, aray, strlen(aray)) >= 0) {
        printf("Backing up blockchain...\n");
    } else {
        printf("Error\n");
    }
   close(dir);
    
}
void read_list(list** node,char* name){
    int dir = open(name, O_RDONLY);
    list* temp = *node;
    char* res ; 
    
    while( (res=my_readline(dir)) != NULL) {
        char* free = malloc(strlen(res)+1);
        clear_node(free, res);
        listnode* term = my_split(free, " ");
        node_add(&temp, atoi(term->array[0]), 1);
        for(int i=1; i<term->size;i++){
                block_id(&temp, term->array[i], atoi(term->array[0]));
        }
        free = 0;
        
    }
    key_dell_node(node, 0);   
}

void my_blockchain(int ac, char** av){

   if(ac > 0){
        list* node = (list*)malloc(sizeof(list));
        int file = open(av[1],O_APPEND);
        char* name = av[1];
        if(file){
            if(file!=3){
                printf("No Backup Found: Starting New Blockchain");
            }  
            
            printf("Restoring From Backup\n");
            read_list(&node,name);

                while(1){
                    char is_syn= sync_sort_flag(&node) ? 's': '-' ; 
                
                    printf("[%c%d]>", is_syn, length_node(&node));
                    fflush(0);
                    char* str = my_readline(0);
                    if(sorted_(str, "") || sorted_(str, " ") || str==0){
                        break;
                    }
                    char* clear = malloc(strlen(str)+1);
                    clear_node(clear, str);
                    listnode* new_node = my_split(clear, " ");
                    int res = my_sort_flag(&node, new_node,name);
                    if(res == 1001)
                        break;
                }
        }
        
    }

}

int main(int ac, char** av){
     my_blockchain(ac,av);
    return 0;
}
