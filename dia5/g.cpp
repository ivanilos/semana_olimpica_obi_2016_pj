#include <stdio.h>
#include <stdlib.h>

/* As operacoes que a raposa pode fazer sao dividir por 2, 3 ou 5. A resposta sera
	a quantidade de cada fator que um tem a mais que o outro desses valores se a 
	quantidade de fatores dos outros primos for igual para os ursos */

int f1[3]; // fatores do queijo do primeiro urso
int f2[3]; // fatores do queijo do segundo urso
int f[] = {2, 3, 5}; // lista de fatores que a raposta consegue dividir

int main(void) {
	int a, b;

	scanf(" %d %d", &a, &b);
	for (int i = 0; i < 3; i++) {
		while(a % f[i] == 0) {
			f1[i]++;
			a /= f[i];
		}
		while(b % f[i] == 0) {
			f2[i]++;
			b /= f[i];
		}
	}
	if (a != b) {
		printf("-1\n");
	} else {
		int res = 0; // resposta;
		for (int i = 0; i < 3; i++) {
			res += abs(f1[i] - f2[i]);
		}
		printf("%d\n", res);
	}
	return 0;
}
