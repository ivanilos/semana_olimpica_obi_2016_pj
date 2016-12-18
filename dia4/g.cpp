#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

/* Se pensarmos nas tarefas como vertices e dependencias como arestas, temos que 
	saber se o grafo eh um DAG (directed acyclic graph, grafo dirigido aciclico).
	Uma das solucoes eh por DFS - se acharmos uma back edge temos um ciclo
	https://en.wikipedia.org/wiki/Depth-first_search#Output_of_a_depth-first_search
	Temos os seguintes tipos de arestas em um grafo dirigido
	- tree edge -> incidente a um vertice ainda nao processado
	- back edge -> incidente a um vertice que comecou mas nao terminou o processamento
	- cross edge -> incidente a um vertice cujo processamento terminou
	Mantemos as cores WHITE (branco), GRAY (cinza) e BLACK (preto) para indicar esses
	estados de processamento
	Uma outra eh tentar fazer a ordenacao topologica dos vertices, se nao existir tal
	ordenacao o grafo possui algum ciclo (fica como exercicio = )) */

const int MAXN = 10005;
const int WHITE = 0;
const int GRAY = 1;
const int BLACK = 2;
vector <int> g[MAXN];
int color[MAXN]; // cor dos vertices
bool loop; // indica se ha ciclo no grafo

void DFS(int node) {
	color[node] = GRAY;

	for (int i = 0; i < (int)g[node].size(); i++) {
		int viz = g[node][i];
		if (color[viz] == WHITE) {
			DFS(viz);
		} else if (color[viz] == GRAY) {
			loop = true;
		}
	}
	color[node] = BLACK;
	return;
}

int main(void) {
	int t;
	int n, m;
	int x, y;

	scanf(" %d", &t);
	while(t--) {
		loop = false;
		scanf(" %d %d", &n, &m);
		for (int i = 1; i <= n; i++) {
			g[i].clear();
			color[i] = WHITE;
		}
		for (int i = 0; i < m; i++) {
			scanf(" %d %d", &x, &y);
			g[x].push_back(y);
		}

		for (int i = 1; i <= n; i++) {
			if (color[i] == WHITE) {
				DFS(i);
			}
		}
		if (loop) {
			printf("SIM\n");
		} else {
			printf("NAO\n");
		}
	}
	return 0;
}

		
	
