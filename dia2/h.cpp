#include <stdio.h>

/* Vamos fazer a soma de prefixos modulo 8 para posicao do vetor. A quantidade de
	subsequencias que terminam no indice x e sao divisiveis por x eh igual a quantidade 
	de indices antes de x cujo resto por 8 eh igual ao resto da soma de prefixo no indice x */

const int MAXN = ((int)1e6 + 5);
int v[MAXN];
int pref[MAXN]; // soma de prefixos modulo 8
int q[8]; // q[x] = quantidade de prefixos modulo x 

int main(void) {
	int n;

	scanf(" %d", &n);
	pref[0] = 0;
	for (int i = 1; i <= n; i++) {
		scanf(" %d", &v[i]);
		pref[i] = (pref[i - 1] + v[i]) % 8;
	}

	q[0] = 1;
	for (int i = 1; i < 8; i++) {
		q[i] = 0;
	}
	long long int res = 0; // resposta
	for (int i = 1; i <= n; i++) {
		res += q[pref[i]];
		q[pref[i]]++;
	}
	printf("%lld\n", res);
	return 0;
}
	
