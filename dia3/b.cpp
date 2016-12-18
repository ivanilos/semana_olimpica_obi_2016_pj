#include <stdio.h>
#include <algorithm>
using namespace std;

/* Ordenamos o vetor a e fazemos uma busca binaria para achar o maior indice com elemento
	de valor menor ou igual ao valor que estamos procurando. Se o indice desse elemento
	for igual a i, a nossa resposta eh i + 1 (pois indexamos a partir de 0).
	Tambem eh possivel usar o upper_bound de C++ (em algorithm) para conseguir esse
	indice */

const int MAXN = 200005;
int a[MAXN];
int b[MAXN];

/* busca binaria, retornamos o maior indice de a[] com valor menor igual a val */
int search(int l, int r, int val) {
	int best = -1; // resposta
	while(l <= r) {
		int mid = (l + r) / 2; // tomar cuidado com overflow de l + r
								// nessa questao nao ha problema
		if (a[mid] > val) {
			r = mid - 1;
		} else {
			best = mid;
			l = mid + 1;
		}
	}
	return best;
}	

int main(void) {
	int n, m;

	scanf(" %d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf(" %d", &a[i]);
	}
	for (int i = 0; i < m; i++) {
		scanf(" %d", &b[i]);
	}
	sort(a, a + n);
	for (int i = 0; i < m; i++) {
		if (i != 0) {
			printf(" ");
		}
		printf("%d", 1 + search(0, n - 1, b[i]));
	}
	printf("\n");
	return 0;
}
	
