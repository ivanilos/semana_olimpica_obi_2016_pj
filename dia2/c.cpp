#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

/* Podemos ordernar a lista de alunos e pagar o k-esimo aluno */

vector <string> v;

int main(void) {
	int n, k;
	string s;

	scanf(" %d %d", &n, &k);
	for (int i = 0; i < n; i++) {
		cin >> s;
		v.push_back(s);
	}
	sort(v.begin(), v.end());
	cout << v[k - 1] << '\n';
	return 0;
}
		
