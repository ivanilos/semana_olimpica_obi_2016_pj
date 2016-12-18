#include <stdio.h>
#define lli long long int

/* A solucao eh por busca binaria na resposta. Se tivermos um numero maximo x, sabemos 
	quantos desses numeros podemos dar para o primeiro amigo e para o segundo e o total
	deles usando o PIE (principio de inclusao exclusao). Ainda, vale que se da com no maximo
	x tambem conseguimos com no maximo x + 1, por isso a busca binaria na resposta.
	Tambem eh possivel achar uma solucao em O(1) para esse problema */

int main(void) {
	int cnt1, cnt2, x, y;

	scanf(" %d %d %d %d", &cnt1, &cnt2, &x, &y);
	lli low = 0;
	lli high = (lli)1e15; // infinito
	lli best = 0;
	while(low <= high) {
		lli mid = (low + high) / 2; // cuidado com overflow
									// nessa questao nao ocorre esse problema
		lli a = mid - mid / x; // quantidade de numeros nao divisiveis por x
		lli b = mid - mid / y; // quantidade de numeros nao divisiveis por y
		lli c = mid - mid / (x * y); // quantidade de numeros nao divisives por x * y
		if (a >= cnt1 && b >= cnt2 && c >= cnt1 + cnt2) {
			best = mid;
			high = mid - 1;
		} else {
			low = mid + 1;
		}
	}
	printf("%lld\n", best);
	return 0;
}
