#include <stdio.h>

/* V = Ds / Dt -> Ds = V * Dt - devemos calcular os valores e soma-los */

const int MAXN = 1005;

int main(void) {
	int n;
	int t, v;
	int res = 0; // resposta;

	scanf(" %d", &n);
	for (int i = 0; i < n; i++) {
		scanf(" %d %d", &t, &v);
		res += t * v;
	}
	printf("%d\n", res);
	return 0;
}
	
