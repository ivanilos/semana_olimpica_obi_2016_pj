#include <stdio.h>
#include <algorithm>
using namespace std;

/* Podemos considerar todas as janelas de tamanho N e calcular o minimo desses valores*/

const int INF = ((int)1e9);
const int MAX_M = 55;
int v[MAX_M];

int main(void) {
	int n, m;

	scanf(" %d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		scanf(" %d", &v[i]);
	}
	sort(v, v + m);

	int res = INF;
	for (int i = 0, j = n - 1; j < m; i++, j++) {
		res = min(res, v[j] - v[i]);
	}
	printf("%d\n", res);
	return 0;
}
