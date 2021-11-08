struct Node{
    char title[50];
    struct Node *next;
};
typedef struct Node node;


void start(node ** queue, int * size);
int isEmpty(node * queue);
node *alocate();
void add(node ** queue, int * size);
void removeNode(node ** queue, int * size);
void freeNode(node ** queue);