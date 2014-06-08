#ifndef H_LIST
#define H_LIST


typedef struct node{
    char symbol;
    double freq;
    int isLeft; /*1 significa que esta a esquerda, 0 esta a direita, -1 se ainda nao foi definido*/
    struct node *father;
    struct node *next;
} Node;




typedef struct queue{

	Node *start;
	Node *end;

} Queue;




extern Queue *p_queue; /*Lista de prioridade*/
extern Node **leaves; /*Vetor contendo o endereco das folhas*/


	
void init_queue();
Node *create_node(char symbol, double freq);
void insert_node(Node *node);
void rem_node();
void print_queue();
int get_size();
void create_leaves();
void create_queue();

#endif /*H_LIST*/

