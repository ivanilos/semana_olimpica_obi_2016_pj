#include <stdio.h>

/* Podemos simular o comportamento do bolominator, iteramos em todas as linhas e colunas
	e caso nao haja morango do mal comemos todos os pedacos de bolo naquela
	linha / coluna */

const int MAXN = 15;
char grid[MAXN][MAXN];
int eat[MAXN][MAXN]; // indica se o pedaco foi comido ou nao

int main(void) {
	int r, c;

	scanf(" %d %d", &r, &c);
	for (int i = 0; i < r; i++) {
		scanf(" %s", grid[i]);
		for (int j = 0; j < c; j++) {
			eat[i][j] = 0;
		}
	}

	// iterar nas linhas
	for (int i = 0; i < r; i++) {
		int can = 1;
		for (int j = 0; j < c; j++) {
			if (grid[i][j] == 'S') {
				can = 0;
				break;
			}
		}
		if (can) {
			for (int j = 0; j < c; j++) {
				eat[i][j] = 1;
			}
		}
	}

	// iterar nas colunas
	for (int j = 0; j < c; j++) {
		int can = 1;
		for (int i = 0; i < r; i++) {
			if (grid[i][j] == 'S') {
				can = 0;
				break;
			}
		}
		if (can) {
			for (int i = 0; i < r; i++) {
				eat[i][j] = 1;
			}
		}
	}

	int res = 0;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			res += eat[i][j];
		}
	}
	printf("%d\n", res);
	return 0;
}

	
