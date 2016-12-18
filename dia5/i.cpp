#include <stdio.h>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

/* A definicao de numero de Giovanni eh a mesma que a definicao de numero de 
	Erdos (ou numero de Bacon para quem prefere = ))
	https://pt.wikipedia.org/wiki/N%C3%BAmero_de_Erd%C5%91s
	Usamos uma BFS para calcular os numeros de Giovanni para todos os convidados
	(vertices) */

const int INF = ((int)1e9);
const int MAX_P = 1005;
vector <int> g[MAX_P];
int dis[MAX_P]; // distancia, ou numero de Giovanni

void BFS(int n) {
	queue <int> fila;
	for (int i = 1; i < n; i++) {
		dis[i] = INF;
	}
	dis[0] = 0;
	fila.push(0);
	while(!fila.empty()) {
		int next = fila.front();
		fila.pop();

		for (int i = 0; i < (int)g[next].size(); i++) {
			int viz = g[next][i];
			if (dis[viz] > 1 + dis[next]) {
				dis[viz] = 1 + dis[next];
				fila.push(viz);
			}
		}
	}
	return;
}	

int main(void) {
	int t;
	int p, d;
	int x, y;

	scanf(" %d", &t);
	for (int caso = 1; caso <= t; caso++) {
		if (caso != 1) {
			printf("\n");
		}
		scanf(" %d %d", &p, &d);
		for (int i = 0; i < p; i++) {
			g[i].clear();
		}
		for (int i = 0; i < d; i++) {
			scanf(" %d %d", &x, &y);
			g[x].push_back(y);
			g[y].push_back(x);
		}

		BFS(p);
		for (int i = 1; i < p; i++) {
			printf("%d\n", dis[i]);
		}
	}
	return 0;
}
	
