#include <stdio.h>
#include <algorithm>
using namespace std;

/* Ordenamos o valor dos soldados. Devemos pagar para aumentar o valor da insignia
	para o menor valor nao utilizado ainda. A estrategia gulosa funciona pois soh podemos
	aumentar o valor das insignias (nao podemos diminuir) */

const int MAXN = 3005;
int v[MAXN];

int main(void) {
	int n;

	scanf(" %d", &n);
	for (int i = 0; i < n; i++) {
		scanf(" %d", &v[i]);
	}
	sort(v, v + n);
	int last = 0; // ultimo valor gasto
	int res = 0; // resposta
	for (int i = 0; i < n; i++) {
		if (v[i] > last) {
			last = v[i];
		} else {
			res += last + 1 - v[i];
			last = last + 1;
		}
	}
	printf("%d\n", res);
	return 0;
}
