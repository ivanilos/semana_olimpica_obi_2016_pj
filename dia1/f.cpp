#include <stdio.h>

/* Se ha um elemento majoritario no vetor, ao tirarmos ele e outro elemento qualquer
	ele continua majoritario, assim achamos um elemento candidato e testamos ele 
	- dica de leitura 
		www.cs.utexas.edu/~moore/best-ideas/mjrty/

	Como o enunciado garante que ha um elemento majoritario, nao precisamos testar
	se o elemento candidato eh majoritario
*/

const int MAXN = 5005;
int v[MAXN];

int main(void) {
	int n;

	while(scanf(" %d", &n) && n) {
		for (int i = 0; i < n; i++) {
			scanf(" %d", &v[i]);
		}

		int cand = -1; // indice do candidato;
		int q = 0; // quantidade do candidato;
		for (int i = 0; i < n; i++) {
			if (cand == -1 || v[i] == cand) {
				cand = v[i];
				q++;
			} else {
				q--;
				if (q == 0) {
					cand = -1;
				}
			}
		}
		printf("%d\n", cand);
	}
	return 0;
}
			
			
	
