#include <stdio.h>

/* Fazemos as somas de prefixos do vetor de doces dados modulo c. Para 0 vizinhos
	temos soma 0, e depois temos mais n valores de somas parciais. Como
	c <= n, algum valor sera repetido (pelo principio da casa dos pombos) - 
	podemos pegar esse intervalo pois ele sera divisivel por c. Assim sempre poderemos
	fazer a divisao dos doces */

const int MAXN = 100005;
int v[MAXN];
int idx[MAXN]; // idx[x] = menor indice onde aparece valor x nas somas parciais
int pref[MAXN]; // soma de prefixos

int main(void) {
	int c, n;

	while(scanf(" %d %d", &c, &n) && !(c == 0 && n == 0)) {
		pref[0] = 0;
		for (int i = 1; i <= n; i++) {
			scanf(" %d", &v[i]);
			pref[i] = (pref[i - 1] + v[i]) % c;
		}
		idx[0] = 0;
		for (int i = 1; i < c; i++) {
			idx[i] = -1;
		}
		for (int i = 1; i <= n; i++) {
			if (idx[pref[i]] == -1) {
				idx[pref[i]] = i;
			} else {
				// imprimir resposta
				for (int j = idx[pref[i]] + 1; j <= i; j++) {
					if (j != idx[pref[i]] + 1) {
						printf(" ");
					}
					printf("%d", j);
				}
				printf("\n");
				break;
			}
		}
	}
	return 0;
}
				
		
		
