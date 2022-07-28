#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int calcular_maximum_bitwise(int v1, int v2) {
	int max;
 
    max = a ^ ((a ^ b) & -(a < b));
 
    return max;
}

int main() {
	int valor_1, valor_2, maior_valor;
	printf("Informe os valores.\n");
	scanf("%d %d", &valor_1, &valor_2);
	maior_valor = calculate_the_maximum(valor_1, valor_2);
	printf("O maior valor e: %d .\n", maior_valor);
	return 0;
}