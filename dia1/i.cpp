#include <stdio.h>
#include <stdlib.h>

/* Seja S a soma das notas. Perceba que ao fazer as operações S não se altera. Então,
	todos conseguem cantar no mesmo tom se N divide S */

const int MAXN = 10005;

int v[MAXN];

int main(void) {
	int n;

	while(scanf(" %d", &n) != EOF) {
		int s = 0; // soma
		int res = 0; // resposta
		for (int i = 0; i < n; i++) {
			scanf(" %d", &v[i]);
			s += v[i];
		}
		int media = s / n;
		if (s % n == 0) {
			for (int i = 0; i < n; i++) {
				res += abs(media - v[i]);
			}
			printf("%d\n", 1 + res / 2);
		} else {
			printf("-1\n");
		}
	}
	return 0;
}
