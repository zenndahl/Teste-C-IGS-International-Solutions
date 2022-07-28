#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//função auxiliar para preencher nosso array de inteiros.
//arry_int sera preenchido com os valores inseridos
//max_elementos quantidade maxima de elementos que o array_int pode receber
//retorna a quantidade de elementos inteiros maiores que zero foram inseridos

int criar_array(int *array_int, int max_elementos){
	int idx = 0;
	char array_str[128];
	char valor[16];
	char *posicao_inicio = NULL;
	char *posicao_fim = NULL;

	printf ("Informe os valores do tipo inteiros, separados por virgula\n");
	scanf ("%s", array_str);
	if (strlen (array_str) > 0){
		posicao_inicio = array_str;
		do {
			posicao_fim = strchr (posicao_inicio, ',');
			memset(valor,0, sizeof(valor));
			if(posicao_fim != NULL) {
				memcpy(valor, posicao_inicio,(int) (posicao_fim - posicao_inicio) );
				posicao_inicio = (posicao_fim + 1 );
			}
			else if(posicao_inicio != NULL){
				memcpy(valor, posicao_inicio,(int) strlen(posicao_inicio) );
			}
			if(strlen(valor)) {
				array_int[idx++] = atoi(valor);
			}
		} while (posicao_fim != NULL && idx < max_elementos);
	}

	printf ("ARRAY -> [" );
	for(int i=0; i<idx; ++i){
		printf ("%d", array_int[i]);
		if(i+1 < idx){
			printf(",");
		}
	}
	printf ("] \n");
	return idx;
}

int maximo_elementos(int valor_ref, int* array, int tamanho_array) {
	int soma = 0;
	int n_agrp = 0;
	int agrupamento_idx = 0;
	int max_val = 0;

	//sera feita uma verificacao para cada elemento do array
	for(int i = 0; i < tamanho_array; i++){
		for(int j = 1; j < tamanho_array; j++){
			soma += *array[i]
			//so verifica elementos diferentes de si mesmo
			if(*array[i] != *array[j]){
				//se a soma com o proximo valor e menor que o valor_ref, adiciona e aumenta o contador, caso contrario continua o loop
				if( soma + *array[j] < valor_ref){
					soma += *array[j];
					n_agrp++;
				}
			}
		}

		//verifica se a nova iteracao obteve maior quantidade de valores
		if(n_agrp > max_val) max_val = n_agrp;
		n_agrp = 0;
	} 

	return max_val;
}

int main () {
const int max_elementos = 128;
int array_int[max_elementos] ;
int qtd_elementos = 0;
int tamanho_array = 0;
int valor_ref = 0;
tamanho_array = criar_array(array_int, max_elementos);
printf("Informe o valor para agrupamento.\n");
scanf ("%d", &valor_ref);
qtd_elementos = maximo_elementos(valor_ref, array_int, tamanho_array);
printf("O numero maximo de agrupamento e [%d].\n", qtd_elementos);
return 0;
}