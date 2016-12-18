#include <stdio.h>
#include <math.h>

/* A solucao eh por busca binaria na resposta. Chutamos um volume que conseguimos dar
	para todos os convidados. Se eh possivel com um volume x, eh verdade que eh possivel 
	com um volume x - EPS, com EPS suficientemente pequeno */

const double PI = acos(-1);
const int MAXN = 10005;
const int MAX_IT = 100;
int r[MAXN]; // raio das tortas

int main(void) {
	int t;
	int n, f;

	scanf(" %d", &t);
	while(t--) {
		scanf(" %d %d", &n, &f);
		f++; // levar em conta que o anfitriao tambem quer bolo
		for (int i = 0; i < n; i++) {
			scanf(" %d", &r[i]);
		}

		double low = 0;
		double high = 1e18; // infinito
		double best = 0; // resposta
		// podemos iterar um numero fixo de vezes ou iterar ate 
		// atingir a precisao requerida
		for (int it = 0; it < MAX_IT; it++) {
			double mid = (low + high) / 2; // chute de um volume
											// ter cuidado se low + high da overflow
			int got = 0; // numero de pessoas que ja conseguiram mid volume de torta
			for (int i = 0; i < n; i++) {
				got += (int)floor((PI * r[i] * r[i]) / mid);
			}
			if (got >= f) {
				best = mid;
				low = mid;
			} else {
				high = mid;
			}
		}
		printf("%.12f\n", best);
	}
	return 0;
}
