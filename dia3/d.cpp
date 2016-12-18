#include <stdio.h>
#include <algorithm>
using namespace std;

/* Usamos vetores para contar a quantidade de pes de cada tamanho. Para um tamanho x
	podemos criar min(l[x], r[x]) pares, onde l[x] e r[x] sao a quantidade de pes
	direitos e esquerdos de tamanho x */

const int MIN_S = 30; // tamanho minimo do par
const int MAX_S = 60; // tamanho maximo de um par
int l[MAX_S + 5]; // pes direitos
int r[MAX_S + 5]; // pes esquerdos

int main(void) {
	int n;
	int s;
	char c;

	while(scanf(" %d", &n) != EOF) {
		for (int i = MIN_S; i <= MAX_S; i++) {
			l[i] = r[i] = 0;
		}
		for (int i = 0; i < n; i++) {
			scanf(" %d %c", &s, &c);
			if (c == 'D') {
				l[s]++;
			} else {
				r[s]++;
			}
		}

		int res = 0;
		for (int i = MIN_S; i <= MAX_S; i++) {
			res += min(l[i], r[i]);
		}
		printf("%d\n", res);
	}
	return 0;
}
		
		
