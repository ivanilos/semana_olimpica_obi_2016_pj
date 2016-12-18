#include <stdio.h>

/* Devemos simular a trajetoria de Xenia de um modo nao mt lento. Cuidado que 
	a resposta pode estourar o tamanho de um inteiro de 32 bits */

int main(void) {
	int n, m;
	long long int res = 0; // resposta
	int pos = 1; // posicao de Xenia
	int x;

	scanf(" %d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		scanf(" %d", &x);
		if (x >= pos) {
			res += x - pos;
		} else {
			res += n - (pos - x);
		}
		pos = x;
	}
	printf("%lld\n", res);
	return 0;
}
	
