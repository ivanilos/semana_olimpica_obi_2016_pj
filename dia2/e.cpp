#include <stdio.h>
#include <algorithm>
using namespace std;

/* A estrategia eh gulosa. Se nosso soldado mais fraco perde do soldado mais fraco do 			oponente, fazemos ele batalhar contra o soldado mais forte do oponente.
		Caso nosso soldado mais fraco consiga ganhar de varios soldados do oponente podemos
		fazer ele batalhar contra o mais fraco do oponente, pois nossos soldados mais fortes
		tambem conseguem derrotar quem nosso soldado mais fraco consegue */

const int MAX_S = 100005;
int a[MAX_S];
int b[MAX_S];

int main(void) {
	int s;

	scanf(" %d", &s);
	for (int i = 0; i < s; i++) {
		scanf(" %d", &a[i]);
	}
	for (int i = 0; i < s; i++) {
		scanf(" %d", &b[i]);
	}
	sort(a, a + s);
	sort(b, b + s);

	int l = 0; // indice do soldado mais fraco do oponente
	int r = s - 1; // indice do soldado mais forte do oponente
	int res = 0; // resposta
	for (int i = 0; i < s; i++) {
		if (b[i] > a[l]) {
			res++;
			l++;
		} else {
			r--;
		}
	}
	printf("%d\n", res);
	return 0;
}
