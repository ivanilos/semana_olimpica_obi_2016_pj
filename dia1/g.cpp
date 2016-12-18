#include <stdio.h>

/* Devemos observar que a quantidade de cortes que o laser faz é igual a quantidade de 
	vezes que o laser abaixa (em altura) */

const int MAX_C = 10005;
int v[MAX_C];

int main(void) {
	int a, c;

	while(scanf(" %d %d", &a, &c) && !(a == 0 && c == 0)) {
		v[0] = v[c + 1] = a;
		for (int i = 1; i <= c; i++) {
			scanf(" %d", &v[i]);
		}

		int res = 0; // resposta
		for (int i = 1; i <= c; i++) {
			if (v[i] < v[i - 1]) {
				res += v[i - 1] - v[i];
			}
		}
		printf("%d\n", res);
	}
	return 0;
}
	
