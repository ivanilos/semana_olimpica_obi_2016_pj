#include <stdio.h>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

/* Imaginando as relacoes como um grafo, queremos saber quais as pessoas mais distantes
	das K fontes. Para achar a distancia podemos usar BFS */

const int INF = ((int)1e9);
const int MAXN = 10005;
vector <int> g[MAXN];
int d[MAXN];

int main(void) {
	int n, k, m;
	int x, y;

	while(scanf(" %d %d %d", &n, &k, &m) && !(n == 0 && m == 0 && k == 0)) {
		queue <int> fila;

		for (int i = 1; i <= n; i++) {
			g[i].clear();
			d[i] = INF;
		}
		for (int i = 0; i < k; i++) {
			scanf(" %d", &x);
			d[x] = 0;
			fila.push(x);
		}
		for (int i = 0; i < m; i++) {
			scanf(" %d %d", &x, &y);
			g[x].push_back(y);
			g[y].push_back(x);
		}

		// BFS
		while(!fila.empty()) {
			int next = fila.front();
			fila.pop();

			for (int i = 0; i < (int)g[next].size(); i++) {
				int viz = g[next][i];
				if (d[viz] > 1 + d[next]) {
					d[viz] = 1 + d[next];
					fila.push(viz);
				}
			}
		}

		int maxi = -1;
		for (int i = 1; i <= n; i++) {
			if (d[i] > maxi && d[i] != INF) {
				maxi = d[i];
			}
		}

		int got = 0; // numero de valores impressos
		for (int i = 1; i <= n; i++) {
			if (d[i] == maxi) {
				if (got != 0) {
					printf(" ");
				}
				got++;
				printf("%d", i);
			}
		}
		printf("\n");
	}
	return 0;
}
	
