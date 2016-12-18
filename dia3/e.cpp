#include <stdio.h>

/* Fazemos uma DFS no grafo implicito. Se conseguimos a partir da posicao (0, 0) alcançar a 
	posicao (4,4) o grupo de policiais ganham, o grupo de ladroes ganham caso contrario */

int grid[10][10];
int used[10][10];
int dx[] = {1, 0, -1, 0}; // vetor de deslocamento x
int dy[] = {0, 1, 0, -1}; // vetor de deslocamento y

// verifica se a posicao (x, y) esta dentro do grid
int is_in(int x, int y) {
	return 0 <= x && x < 5 && 0 <= y && y < 5;
}

void DFS(int x, int y) {
	used[x][y] = 1;
	
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (is_in(nx, ny) && !used[nx][ny] && grid[nx][ny] == 0) {
			DFS(nx, ny);
		}
	}
	return;
}

int main(void) {
	int t;

	scanf(" %d", &t);
	while(t--) {
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 5; j++) {
				used[i][j] = 0;
				scanf(" %d", &grid[i][j]);
			}
		}
		DFS(0, 0);
		if (used[4][4] == 1) {
			printf("COPS\n");
		} else {
			printf("ROBBERS\n");
		}
	}
	return 0;
}
	
