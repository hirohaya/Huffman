#ifndef H_TREE
#define H_TREE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "list.h"



extern Node **btree;
extern int nleaves;


void init_tree();
void build_tree();
void print_tree();
void print_code(Node *leaf, FILE *oFile);
void compact_file(char *iname, char *oname);
#endif /*H_TREE*/

