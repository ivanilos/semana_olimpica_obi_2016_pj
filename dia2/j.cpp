#include <stdio.h>

/* A melhor estrategia sempre eh tirar uma bola da caixa, entao basta verificarmos a 
	quantidade de bolas que cada jogador tem */

int main(void) {
	int n1, n2;

	scanf(" %d %d", &n1, &n2);
	if (n1 > n2) {
		printf("First\n");
	} else {
		printf("Second\n");
	}
	return 0;
}
