#include <stdio.h>

void calc_fatorial(int *valor_ft, int valor_n){
	*valor_ft = valor_n;
	while(valor_n > 1){
		valor_n--;
		*valor_ft =  *valor_ft * valor_n;
	}
}


int main() {
int v, vf = 0;
int *pv = &v;
scanf("%d", &v);
calc_fatorial(vf, pv);
printf("Valor fatorial de: [%d] é [%d]", v, vf);
return 0;
}