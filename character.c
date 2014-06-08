#include "character.h"

double characters[126];

/*Defini o valor inicial de todos so nos do vetor characters[] como zero, pois ainda nao houve nenhuma leitura.*/
void init_array(){

  int i;

    for(i = 0; i < 126; i++)
	    characters[i] = 0;
}
/*Conta o numero de aparicoes de cada caractere no arquivo de entrada e calcula a sua frequencia.*/
void count_characters(char *file_name){ 

  FILE *pFile;
  char c;	
  int i;
  int nchar;

  	nchar = 0;
        i = 0;
	pFile = fopen(file_name, "r");
	
	while(!feof(pFile)){
		c = fgetc(pFile);
		i = c;
		characters[i-1]++;
		nchar++;
	}

	for(i = 0; i < 126; i++) characters[i] = characters[i]/nchar * 100;
	fclose(pFile);
}

