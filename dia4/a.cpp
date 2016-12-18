#include <stdio.h>
#include <vector>
using namespace std;

/* Fazendo cada pessoa um vertice do grafo e cada relacao de parentesco um vertice, cada
	familia eh uma componente conexa do grafo. Entao devemos contar quantas componentes
	conexas o grafo tem */

const int MAXN = 50005;
vector <int> g[MAXN];
int used[MAXN];

void DFS(int node) {
	used[node] = 1;
	for (int i = 0; i < (int)g[node].size(); i++) {
		int viz = g[node][i];
		if (!used[viz]) {
			DFS(viz);
		}
	}
	return;
}

int main(void) {
	int n, m;
	int x, y;

	scanf(" %d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
		used[i] = 0;
	}
	for (int i = 0; i < m; i++) {
		scanf(" %d %d", &x, &y);
		g[x].push_back(y);
		g[y].push_back(x);
	}

	int res = 0; // resposta
	for (int i = 1; i <= n; i++) {
		if (!used[i]) {
			res++;
			DFS(i);
		}
	}
	printf("%d\n", res);
	return 0;
}
	
