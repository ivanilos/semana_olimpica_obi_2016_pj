#include <stdio.h>
#include <algorithm>
using namespace std;

/* A solucao eh por busca binaria na resposta. Se chutarmos que conseguimos manter as 
	vacas pelo menos x unidades afastadas, podemos colocar elas de maneira gulosa 
	nas barracas, a partir da primeira e nas proximas que estao na distancia minima
	da ultima vaca coloca e tem distancia maior que x. */

const int INF = ((int)1e9 + 5);
const int MAXN = ((int)1e5 + 5);
int v[MAXN];

int main(void) {
	int t;
	int n, c;

	scanf(" %d", &t);
	while(t--) {
		scanf(" %d %d", &n, &c);
		for (int i = 0; i < n; i++) {
			scanf(" %d", &v[i]);
		}
		sort(v, v + n);

		int low = 0;
		int high = INF;
		int best = 0; // resposta
		while(low <= high) {
			int mid = (low + high) / 2; // cuidado com overflow
										// nessa questao nao ha problema
			int got = 0; // numero de vacas que conseguimos colocar;
			int last = -INF; // posicao da ultima vaca colocada
			for (int i = 0; i < n; i++) {
				if (v[i] - last >= mid) {
					got++;
					last = v[i];
				}
			}
			if (got >= c) {
				best = mid;
				low = mid + 1;
			} else {
				high = mid - 1;
			}
		}
		printf("%d\n", best);
	}
	return 0;
}
