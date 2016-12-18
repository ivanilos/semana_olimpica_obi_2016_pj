#include <stdio.h>

/* Como temos N cidades(vertices)e N estradas(arestas), cada cidade alcança toda outra
	se tivermos exatamente um ciclo. Podemos checar se é formado um ciclo se
	- todo vertice tem grau de entrada 1 e grau de saida 1
	- um vertice alcança todos os outros */

const int MAXN = 10005;
int next[MAXN]; // next[x] = vertice apos percorrermos a aresta saindo do vertice x 
int in[MAXN]; // grau de entrada
int out[MAXN]; // grau de saida

int DFS(int x, int s) {
	if (x != s && next[x] == s) {
		return 1;
	}
	return 1 + DFS(next[x], s);
}

int main(void) {
	int n;
	int x, y;
	bool ok = true; // resposta

	scanf(" %d", &n);
	for (int i = 1; i <= n; i++) {
		in[i] = out[i] = 0;
	}
	for (int i = 0; i < n; i++) {
		scanf(" %d %d", &x, &y);
		out[x]++;
		in[y]++;
		next[x] = y;
	}
	
	// checar condicao de graus
	for (int i = 1; i <= n; i++) {
		if (in[i] != 1 || out[i] != 1) {
			ok = false;
		}
	}

	int tot = 0;
	if (ok == true) {
		tot = DFS(1, 1); // numero de vertices no ciclo
	}
	if (tot < n) {
		ok = false;
	}
	if (ok) {
		printf("S\n");
	} else {
		printf("N\n");
	}
	return 0;
}
	
