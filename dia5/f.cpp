#include <stdio.h>

/* Imaginando o cenario como um grafo, cada bolsa eh um vertice e devemos achar 
	o numero total de componentes conexas - podemos fazer isso usando DFS */

const int MAXN = 105;
char grid[MAXN][MAXN];
int m, n;

int dx[] = {-1, 0, 1, 1, 1, 0, -1, -1};
int dy[] = {1, 1, 1, 0, -1, -1, -1, 0};

int is_in(int x, int y) {
	return 0 <= x && x < m && 0 <= y && y < n;
}

void DFS(int x, int y) {
	grid[x][y] = '*';

	for (int i = 0; i < 8; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (is_in(nx, ny) && grid[nx][ny] == '@') {
			DFS(nx, ny);
		}
	}
	return;
}	

int main(void) {

	while(scanf(" %d %d", &m, &n) && m) {
		for (int i = 0; i < m; i++) {
			scanf(" %s", grid[i]);
		}
		
		int res = 0;
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (grid[i][j] == '@') {
					res++;
					DFS(i, j);
				}
			}
		}
		printf("%d\n", res);
	}
	return 0;
}
	
