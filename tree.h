#ifndef H_TREE
#define H_TREE

#include <stdio.h>
#include <stdlib.h>


typedef struct node{
    char caracter;  /*Caracter do texto*/
    int freq;       /*frequencia do caracter*/
    struct node *r;
    struct node *l;
} Node;


#endif
