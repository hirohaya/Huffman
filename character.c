#include "character.h"

double characters[126];

/*Defini o valor inicial de todos so nos do vetor characters[] como zero, pois ainda nao houve nenhuma leitura.*/
void init_array(){

  int i;

    for(i = 0; i < 126; i++)
	    characters[i] = 0;
}
/*Conta o numero de aparicoes de cada caractere no arquivo de entrada e calcula a sua frequencia. Inicialmente, contamos apenas os caracteres imprimiveis e os caracteres relativos a Newline e TAB.*/
void count_characters(char *file_name){ 

  FILE *pFile;
  char c;	
  int i;
  int nchar;

  	nchar = 0;
        i = 0; /*gcc, eu te odeio*/
	pFile = fopen(file_name, "r");
	
	while(!feof(pFile)){
		c = fgetc(pFile);
		
		if((c >= 32 && c <= 126) || c == 10 || c == 9){
			i = c;
			characters[i-1]++;
			nchar++;
		}
	}

	for(i = 0; i < 126; i++) characters[i] = characters[i]/nchar * 100;
	/*Print para testes do array de caracteres*/
	for(i = 0; i < 126; i++){
		if((characters[i] > 0 && i >= 31 && i <= 125) || i == 9 || i == 8){
			if(i == 9) printf("Newline tem frequencia de %f%%.\n", characters[i]);
			else if(i == 8)	printf("TAB tem frequencia de %f%%.\n", characters[i]);
			else	printf("%c tem frequencia de %f%%.\n", (i+1), characters[i]);
		}
	}
	fclose(pFile);
}



