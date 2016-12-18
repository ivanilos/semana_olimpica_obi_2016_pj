#include <stdio.h>
#include <queue>
#include <stack>
using namespace std;

/* Simulamos uma fila, uma pilha e uma fila de prioridade, se alguma operacao nao
	corresponder a nossa simulacao sabemos que nao pode ser aquela estrutura.
	Usamos uma mascara de bits para manter controle quais as estruturas possiveis */

// zerar bit x da variavel mask - passamos mask por referencia
void zerar(int x, int &mask) {
	mask &= ~(1 << x);
	return;
}

int main(void) {
	int n;
	int op, x;

	while(scanf(" %d", &n) != EOF) {
		stack <int> st; // pilha
		queue <int> fila; // fila
		priority_queue <int> pq; // fila de prioridade
		int mask = (1 << 3) - 1; // mascara de bits que indica estruturas
								// possiveis
								// bit 0 - fila
								// bit 1 - pilha
								// bit 2 - fila de prioridade
		while(n--) {
			scanf(" %d %d", &op, &x);
			if (op == 1) {
				st.push(x);
				fila.push(x);
				pq.push(x);
			} else {
				if (fila.empty() || fila.front() != x) {
					zerar(0, mask);
				} else {
					fila.pop();
				}
				if (st.empty() || st.top() != x) {
					zerar(1, mask);
				} else {
					st.pop();
				}
				if (pq.empty() || pq.top() != x) {
					zerar(2, mask);
				} else {
					pq.pop();
				}
			}
		}
		if (mask == 0) {
			printf("impossible\n");
		} else if (mask == 1) {
			printf("queue\n");
		} else if (mask == 2) {	
			printf("stack\n");
		} else if (mask == (1 << 2)) {
			printf("priority queue\n");
		} else {
			printf("not sure\n");
		}
	}
	return 0;
}
					
			
	
