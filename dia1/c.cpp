#include <stdio.h>

/* simulamos o caminho do robo atualizando a matriz conforme ele se move */

const int MAXN = 1005; // valor maximo das coordenadas
						// sempre eh bom deixar um valor de folga
						// maximo = 1000 -> MAXN = 1005

int dx[] = {0, 1, 0, -1}; // vetor de deslocamento em linha
int dy[] = {1, 0, -1, 0}; // vetor de deslocamento em coluna

int l, c;
int mat[MAXN][MAXN];
int sx, sy; // posicao do robo

//verifica se a posicao [x][y] esta dentro da matriz
int is_in(int x, int y) {
	return 1 <= x && x <= l && 1 <= y && y <= c;
} 

// movimentacao do robo
void move(int x, int y) {
	mat[x][y] = 0; // marcar para nao precisar se mover
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (is_in(nx, ny) && mat[nx][ny] == 1) {
			move(nx, ny);
			break;
		}
	}
	return;
}

int main(void) {

	scanf(" %d %d", &l, &c);
	for (int i = 1; i <= l; i++) {
		for (int j = 1; j <= c; j++) {
			scanf(" %d", &mat[i][j]);
		}
	}
	scanf(" %d %d", &sx, &sy);

	move(sx, sy);
	printf("%d %d\n", sx, sy);

	return 0;
}

	

