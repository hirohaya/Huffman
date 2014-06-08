#include <stdio.h>
#include <stdlib.h>

#include "list.h"



Queue *p_queue;
Node **leaves;
double characters[126];



void init_queue(){

	p_queue = malloc(sizeof(Queue));
	p_queue->start = NULL;
	p_queue->end = NULL;
}



void create_queue(){

  int i;
  	for(i = 0; i < 126; i++)
		if(characters[i] > 0) 
			insert_node((create_node((i+1), characters[i])));

}

	
	
Node *create_node(char symbol, double freq){

  Node *new;

  	new = malloc(sizeof(Node));
	new->symbol = symbol;
	new->freq = freq;
	new->father = NULL;
	new->next = NULL;
	new->isLeft = -1;

	return new;
}



void insert_node(Node *node){

  Node *p;
    
    p = p_queue->start;
    
    /*Insere o primeiro elemento se a fila estiver vazia*/
    if (p == NULL){
	/*Se o p_queue->start apontar para NULL, a lista esta vazia*/
	p_queue->end = node;
        p_queue->start = node;
        node->next = NULL;
    } 
    else{
        /*Faz p percorrer a lista ate que a frequencia de p seja menor que a frequencia de node e que a frequencia de p->next seja maior que a frequencia de node*/
        while(node->freq > p->freq &&  p->next != NULL && node->freq > (p->next)->freq) p = p->next;
	
	/*Caso p seja o inicio da fila, temos que inserir node antes de p*/
	if(node->freq < p->freq){
		node->next = p;
		p_queue->start = node;
	}
	else{
       		 /*Insere depois do elemento com frequecia imediatamente menor e antes do elemento comf requencia imediatamente maior que a frequencia de node*/
        	node->next = p->next;
        	p->next = node;

		/*Caso p seja o final da fila, fazemos com que node seja o novo final da fila*/
		if(p_queue->end == p){
			p_queue->end = node;
		}
	}


    }
}	



void rem_node(){

	p_queue->start = (p_queue->start)->next;
}



void print_queue(){

  Node *p;

      for(p = p_queue->start; p != NULL; p = p->next)
	      printf("Caracter: %c       Frequencia: %f%% ", p->symbol, p->freq);
}



int get_size(){

  int size;
  Node *p;
  	
	size = 0;
	
	for(p = p_queue->start; p != NULL; p = p->next)	size++;
	
	return size;
}



void create_leaves(){

  Node *p;
  int i;
	
  	i = 0;
	leaves = malloc(get_size()*sizeof(Node));

	for(p = p_queue->start; p != NULL; p = p->next){
		leaves[i] = p;
		i++;
	}
}
