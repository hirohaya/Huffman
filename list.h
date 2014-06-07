#ifndef H_LIST
#define H_LIST


typedef struct node{
    char symbol;
    double freq;
    int isRight; /*1 significa que esta a direita, 0 esta a esquerda*/
    struct node *father;
    struct node *next;
} Node;




typedef struct queue{

	Node *start;
	Node *end;

} Queue;




extern Queue p_queue; /*Lista de prioridade*/

	
void init_queue();
void insert_node(Node *node);

#endif /*H_LIST*/
