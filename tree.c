#include "tree.h"



Queue *p_queue;
Node **leaves;
Node **btree;
int nleaves;

void init_tree(){

	nleaves = get_size();
	btree = malloc((2 * nleaves - 1)*sizeof(Node));
}



void build_tree(){

  Node *p;
  Node *q;
  Node *new;
  int i;

  	i = 0;

	while(get_size() > 1){

		p = p_queue->start;
		rem_node();
		q = p_queue->start;
		rem_node();

		new = create_node(0, (p->freq + q->freq));

		p->father = new;
		p->isLeft = 1;
		
		q->father = new;
		q->isLeft = 0;

		insert_node(new);
		btree[i] = new;
		
		i++;
	}
}

void print_tree(){

  Node *p;
  int i;
  	
  	for(i = 0; i < nleaves; i++){
  		for(p  = leaves[i]; p != NULL; p = p->father){
			printf("%f\n", p->freq);
		}
		puts("");
	}
}



void print_code(Node *leaf, FILE *oFile){

	if(leaf->father->father != NULL)
		print_code(leaf->father, oFile);
	fprintf(oFile, "%d", leaf->isLeft);
}



void compact_file(char *iname, char *oname){

  FILE *iFile;
  FILE *oFile;
  int i;
  char c;

  	iFile = fopen(iname, "r");
	oFile = fopen(oname, "w");
	/*Formatacao da impressao da codificao: "[valor inteiro do caractere na tabela ASCII]:[Codificacao do caractere]*/
	fprintf(oFile, "%d\n", nleaves);
	/*Imprime no arquivo de saida (compactado) a codificacao de cada caractere utilizado*/
	for(i = 0; i < nleaves; i++){
		fprintf(oFile, "%d:", leaves[i]->symbol);
		print_code(leaves[i], oFile);
		fprintf(oFile, "\n");
	}

/*	while(!feof(iFile)){
		c = fgetc(iFile);
		for(i = 0; i < nleaves-1; i++)
			if(leaves[i]->symbol == c)
				break;
		print_code(leaves[i], oFile);
	}*/


	fprintf(oFile, "\n");
	fclose(iFile);
	fclose(oFile);
}

