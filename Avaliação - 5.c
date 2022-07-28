#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_SORTEIO 30
#define MAX_MARCACAO 15

void avaliar_marcacao(int *sorteio, int tam_sorteio, int *cartela, char* marcacao, int tam_marcacao) {
	for(int i = 0; i < tam_marcacao; i++){
		for(j = 0; j < tam_sorteio; j++){

			//caso encontre o numero no sorteio, marca o 'X' e sai do loop
			if(*sorteio[i] == *sorteio[j]){
				*marcacao[i] = "X";
				break;
			}

			//caso não encontre o numero no sorteio ate o ultimo numero, marca o 'O' e reinicia o j
			if(j == tam_sorteio){
				*marcacao[i] = "X";
				j = 0;
			}
		}
	}
}

int main() {
	int sorteio[MAX_SORTEIO] = {11,21,5,1,8,20,60,58,44,49,25,12,14,27,50,56,9,29,33,10,40,6,51,55,22};
	int cartela[MAX_MARCACAO] = {2,15,33,41,48,3,20,35,44,57,12,29,40,50,60};
	char marcacao[MAX_MARCACAO] = {""};

	avaliar_marcacao(sorteio, MAX_SORTEIO, cartela, marcacao, MAX_MARCACAO);

	int idx = 0;

	do {
		printf(" %c ", marcacao[idx]);
		if((++idx)%5 == 0) {
			printf("\n");
		}
	}while (idx < MAX_MARCACAO);
	return 0;
}