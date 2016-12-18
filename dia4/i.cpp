#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <stack>
#include <string>
using namespace std;

/* A solucao eh gulosa. Vamos achar para todo x, 1 <= x <= d qual o maior numero P possivel
	removendo exatamente x caracteres. Para a resposta de x + 1 podemos retirar um digito
	de P usando um argumento guloso similar. Para achar o maior numero removendo um digito
	do numero, vamos remover o primeiro digito tal que ele seja menor que o proximo digito.
	Caso nao exista esse digito, devemos observar que a sequencia de digitos eh nao
	crescente, entao devemos retirar da parte menos significativa do numero ate que
	tenhamos feito as K remocoes. 
	Usaremos uma pilha para nos auxiliar nas operacoes e manter o numero de operacoes
	linear (O(n)) */

const int MAXN = ((int)1e5 + 5);
char s[MAXN];

int main(void) {
	int n, d;

	while(scanf(" %d %d", &n, &d) && !(n == 0 && d == 0)) {
		stack <char> st;
		scanf(" %s", s);

		for (int i = 0; s[i] != '\0'; i++) {
			if (st.empty() || st.top() > s[i]) {
				st.push(s[i]);
			} else {
				while(d > 0 && !st.empty() && st.top() < s[i]) {
					st.pop();
					d--;
				}
				st.push(s[i]);
			}
		}
		while(d > 0) {
			st.pop();
			d--;
		}
		string res = ""; // resposta
		while(!st.empty()) {
			res += st.top();
			st.pop();
		}
		reverse(res.begin(), res.end());
		cout << res << '\n';
	}
	return 0;
}






