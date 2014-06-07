#include <stdio.h>
#include <stdlib.h>

#include "tree.h"
#include "character.h"

double characters[126];

int main(int argv, char **argc){


	init_array();	
	count_characters(argc[1]);


       return 0;
}
