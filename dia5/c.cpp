#include <stdio.h>
#include <string.h>
#include <algorithm>
#define lli long long int
using namespace std;

/* A solucao eh por programacao dinamica. Seja dp[x] = numero de sequencias validas
	que comecam em x. A resposta estara em dp[0] e as transicoes (se validas)
	sao pegar um digito e ir para dp[x + 1] ou 2 digitos e ir para dp[x + 2] */

const int MAXN = 5005;
char s[MAXN];
lli dp[MAXN];
int n;

lli solve(int pos) {
	if (pos >= n) { // existe um jeito de decodificar uma sequencia vazia
		return 1;
	}
	if (dp[pos] != -1) { // se ja calculamos retornar resposta
		return dp[pos];
	}
	if (s[pos] == '0') { // nao podemos comecar com 0
		return 0;
	}
	lli aux = solve(pos + 1);
	if (pos + 1 < n) {
		int val = 10 * (s[pos] - '0') + s[pos + 1] - '0'; // valor se pegarmos 2 digitos
		if (1 <= val && val <= 26) {
			aux += solve(pos + 2);
		}
	}
	dp[pos] = aux;
	return aux;
}  
	
int main(void) {
	while(scanf(" %s", s) && s[0] != '0') {
		n = strlen(s);
		for (int i = 0; i < n; i++) {
			dp[i] = -1; // indicar que nao computamos
		}
		lli res = solve(0);
		printf("%lld\n", res);
	}
	return 0;
}
		
