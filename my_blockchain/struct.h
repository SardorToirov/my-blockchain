typedef struct s_bocklist {
    char* data;
    int  size;
    struct s_bocklist* next;
      char** array;
} listnode;

typedef struct s_nodelist {
    int id;
    listnode* blocklist;
    struct s_nodelist* next;
    char* name;
} list;

