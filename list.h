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




extern Queue *p_queue; /*Lista de prioridade*/
extern Node **leaves; /*Vetor contendo o endereco das folhas*/


	
void init_queue();
Node *create_node(char symbol, double freq);
void insert_node(Node *node);
void rem_node();
void print_queue();
int get_size();
void create_leaves();

#endif /*H_LIST*/

