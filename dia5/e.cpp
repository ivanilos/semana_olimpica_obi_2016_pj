#include <stdio.h>

/* Devemos observar que soh vale a pena trocar um peca com valor par em uma face
	e impar na outra. Devemos verificar a soma dos valores pra cima e dos pra baixo
	e assim fazer a escolha - soh conseguimos fazer ambas somas serem par se ambas ja forem
	par ou entao ambas forem impar e existir uma peca em que possamos inverter a paridade
	A resposta sempre sera 0, 1 ou -1 */

int main(void) {
	int n;
	int u = 0; // soma dos valores de cima
	int d = 0; // soma dos valores de baixo
	int impar_par = 0; // indica se podemos ganhar com paridade impar pra cima e par pra baixo
	int par_impar = 0; // indica se podemos ganhar com paridade par pra cima e impar pra baixo
	int x, y;

	scanf(" %d", &n);
	for (int i = 0; i < n; i++) {
		scanf(" %d %d", &x, &y);
		u += x;
		d += y;
		if (x % 2 == 0 && y % 2 == 1) {
			impar_par = 1;
		} 
		if (x % 2 == 1 && y % 2 == 0) {
			par_impar = 1;
		}
	}

	if (u % 2 == 0 && d % 2 == 0) {
		printf("0\n");
	} else if (u % 2 == 1 && d % 2 == 1 && (par_impar == 1 || impar_par == 1)) {
		printf("1\n");
	} else {
		printf("-1\n");
	}
	return 0;
}
