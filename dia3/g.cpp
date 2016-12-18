#include <stdio.h>

/* Fazemos uma DFS para atravessar e pintar os quadrados do grid. A tecnica tambem eh 
	conhecida como flood fill */

const int MAXN = 55;
char grid[MAXN][MAXN];
int n, m;

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

int is_in(int x, int y) {
	return 0 <= x && x < n && 0 <= y && y < m;
}

void DFS(int x, int y) {
	grid[x][y] = 'T';

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		
		if (is_in(nx, ny) && grid[nx][ny] == 'A') {
			DFS(nx, ny);
		}
	}
	return;
}

int main(void) {

	while(scanf(" %d %d", &n, &m) && !(n == 0 && m == 0)) {
		for (int i = 0; i < n; i++) {
			scanf(" %s", grid[i]);
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (grid[i][j] == 'T') {
					DFS(i, j);
				}
			}
		}
		
		for (int i = 0; i < n; i++) {
			printf("%s\n", grid[i]);
		}
		printf("\n");
	}
	return 0;
}
		
		
	
