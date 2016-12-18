#include <stdio.h>

/* Existem varios jeitos de resolver esse problema. Um possivel jeito eh observar que 
	no nivel N usamos N - 1 cartas de apoio para o nivel de cima (cartas deitadas)
	e 2 * N cartas de pe - eh possivel derivar uma formula ou precomputar todos os valores
	e depois imprimi-los */

const int MAXN = ((int)1e6 + 5);
const int MOD = ((int)1e6 + 7);

int dp[MAXN];

int main(void) {
	int t;	
	int n;
	
	dp[1] = 2;
	for (int i = 2; i < MAXN; i++) {
		dp[i] = (dp[i - 1] + i - 1 + 2 * i) % MOD;
	}

	scanf(" %d", &t);
	while(t--) {
		scanf(" %d", &n);
		printf("%d\n", dp[n]);
	}
	return 0;
}
	
