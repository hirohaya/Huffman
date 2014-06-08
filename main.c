#include <stdio.h>
#include <stdlib.h>

#include "character.h"
#include "list.h"
#include "tree.h"



int main(int argv, char **argc){


  	init_queue();
	init_array();	
	count_characters(argc[2]);
	create_queue();
 	/*Teste das funcoes de filas*/
	/*print_queue();*/
	create_leaves();
	init_tree();
	build_tree();
	print_tree();
	compact_file(argc[2], argc[4]);	
	return 0;
}

