#include <stdio.h>
#include <stdlib.h>

#include "list.h"



Queue p_queue;



void init_queue(){

	p_queue.start = NULL;
	p_queue.end = NULL;
}


/*
void insert_node(Node *node){

  Node *p;
  int aux;

	p = p_queue.end;

	while(node->freq < p->freq && p->next != NULL)	p = p->next;
	       
	node->next = p->next;
	p->next = node;
			        
	if(p->freq > node->freq){	
		aux = node->freq;
		node->freq = p->freq;
		p->freq = aux;
    	}
}	*/
