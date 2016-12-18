#include <stdio.h>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

/* Fazendo cada pilar um vertice no grafo e cada ponte um aresta com peso, precisamos 
	achar o menor caminho de 0 a N + 1. Usamos o algoritmo de Dijkstra pois os pesos 
	(numero de buracos) eh >= 0 */

const int MAXN = 1005;
const int INF = ((int)1e9);

// Usamos a representacao de vetores paralelos, onde o primeiro vector (g) indica o vizinho
// e o segundo (w) indica o peso da aresta correspondente
// Existem muitas outras representacoes possiveis
vector <int> g[MAXN];
vector <int> w[MAXN];
int d[MAXN];

int dijkstra(int s, int n) {
	priority_queue <pair <int, int> > pq;
	for (int i = 0; i <= n; i++) {
		d[i] = INF;
	}
	d[s] = 0;
	pq.push(make_pair(-d[s], s)); // a fila de prioridade de C++ eh sempre de maximo
									// por isso inserimos -d[s] ao inves de d[s]
	while(!pq.empty()) {
		int cost = -pq.top().first;
		int next = pq.top().second;
		pq.pop();
		
		if (d[next] < cost) {
			continue;
		}
		for (int i = 0; i < (int)g[next].size(); i++) {
			int viz = g[next][i];
			if (d[viz] > w[next][i] + d[next]) {
				d[viz] = w[next][i] + d[next];
				pq.push(make_pair(-d[viz], viz));
			}
		}
	}
	return d[n];
}

int main(void) {
	int n, m;
	int x, y, z;

	scanf(" %d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		scanf(" %d %d %d", &x, &y, &z);
		g[x].push_back(y);
		g[y].push_back(x);
		w[x].push_back(z);
		w[y].push_back(z);
	}
	int res = dijkstra(0, n + 1);
	printf("%d\n", res);
	return 0;
}
