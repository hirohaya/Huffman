#include <stdio.h>
#include <stdlib.h>

#include "character.h"
#include "list.h"
#include "tree.h"



double characters[126];
Queue *p_queue;


int main(int argv, char **argc){

  int i;

  	init_queue();
	init_array();	
	count_characters(argc[1]);

 	for(i = 0; i < 126; i++)
		if((characters[i] > 0 && i >= 31 && i <= 125) || i == 9 || i == 8)
			/*Lisp aproves*/
			insert_node((create_node((i+1), characters[i])));
	/*Teste das funcoes de filas*/
	print_queue();
	printf("Temos %d caracteres diferentes.\n", get_size());
	create_leaves();

       return 0;
}

