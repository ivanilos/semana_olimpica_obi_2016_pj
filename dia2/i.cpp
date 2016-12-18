#include <stdio.h>
#include <algorithm>
using namespace std;

/* Algumas caixas devem levar 2 sinos mas algumas podem levar 1 apenas. Nesse caso devemos
	levar sinos maiores sozinhos senao a resposta pode piorar. Agora temos que colocar sinos
	em duplas, se nao colocarmos o maior com o menor, o segundo maior com o segundo menor e
	assim por diante a resposta pode piorar */

const int MAXN = ((int)1e5 + 5);
int v[MAXN];

int main(void) {
	int n, k;
	int res = 0; // resposta

	scanf(" %d %d", &n, &k);
	for (int i = 0; i < n; i++) {
		scanf(" %d", &v[i]);
		res = max(res, v[i]);
	}
	while(n >= 0 && 2 * k >= n) {
		n--;
		k--;
	}
	k++;
	for (int i = 0; i < n; i++, n--) {
		res = max(res, v[i] + v[n]);
	}
	printf("%d\n", res);
	return 0;
}
