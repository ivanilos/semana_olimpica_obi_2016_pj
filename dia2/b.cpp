#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

/* Podemos criar uma variavel nova e uma regra de ordenacao para ela (atraves de uma
	funcao ou overload do operador < */

const int MAXN = 105;

struct pais {
	int medal; // medalhas
	int idx; // indice do pais

	pais() {}
	pais(int medal, int idx):medal(medal), idx(idx) {}
};

int medal[MAXN]; // numero de medalhas
vector <pais> v; // lista de paises

bool comp(const pais &a, const pais &b) {
	return a.medal > b.medal || (a.medal == b.medal && a.idx < b.idx);
}

int main(void) {
	int n, m;
	int x;

	scanf(" %d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
		medal[i] = 0;
	}
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < 3; j++) {
			scanf(" %d", &x);
			medal[x]++;
		}
	}
	for (int i = 1; i <= n; i++) {
		v.push_back(pais(medal[i], i));
	}
	sort(v.begin(), v.end(), comp);
	for (int i = 0; i < (int)v.size(); i++) {
		if (i != 0) {
			printf(" ");
		}
		printf("%d", v[i].idx);
	}
	printf("\n");
	return 0;
}
		
