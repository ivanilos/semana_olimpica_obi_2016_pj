#include <stdio.h>
#include <algorithm>
using namespace std;

/* Seja a seguinte formulacao de programacao dinamica DP[POS][MOVE] = 
	maior distancia que conseguimos alcancar para os primeiros POS dominos
	fazendo MOVE movimentos. A resposta entao sera o menor valor de MOVE
	tal que DP[N - 2][MOVE] >= a distancia do primeiro domino ao ultimo. */

const int INF = ((int)1e9);
const int MAXN = 1005;
int v[MAXN];
int dp[MAXN][MAXN];
int dist[MAXN]; // dist[x] = distancia do primeiro ate o domino de indice x

int main(void) {
	int n, h;

	while(scanf(" %d %d", &n, &h) && !(n == -1 && h == -1)) {
		for (int i = 1; i < n; i++) {
			scanf(" %d", &v[i]);
			dist[i] = dist[i - 1] + v[i];
		}

		// inicializacao da DP
		// para o primeiro domino sempre conseguimos uma distancia h 
		// independente de quantos movimentos fazemos
		for (int j = 0; j < n; j++) {
			dp[0][j] = h;
		}

		// Para os outros dominos a distancia maxima depende dos valores anteriores
		for (int i = 1; i < n; i++) {
			if (dp[i - 1][0] >= dist[i]) {
				dp[i][0] = dist[i] + h;
			} else {
				dp[i][0] = dp[i - 1][0];
			}
		}
		

		/* a distancia maxima para o i primeiros dominos com j movimentos eh
		- a distancia maxima dos i - 1 dominos com j movimentos se assim nao alcancamos
			a posicao do iesimo domino, ou a distancia dele desde o inicio + h (nesse caso
			nao movemos o iesimo domino
		- movemos o iesimo domino para a melhor posicao possivel, que eh a posicao 
			maxima dos i-1 primeiros dominos com j - 1 movimentos (totalizando j 
			movimentos)
		*/ 
		for (int i = 1; i < n - 1; i++) {
			for (int j = 1; j < n; j++) {
				if (dp[i - 1][j] >= dist[i]) {
					dp[i][j] = dist[i] + h;
				} else {
					dp[i][j] = dp[i - 1][j];
				}
				dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + h);
			}
		}

		int res = -1;
		for (int i = 0; i < n - 1; i++) {
			if (dp[n - 2][i] >= dist[n - 1]) {
				res = i;
				break;
			}
		}
		printf("%d\n", res);
	}
	return 0;
}

	
