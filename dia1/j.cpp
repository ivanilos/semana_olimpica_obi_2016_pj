#include <stdio.h>
#include <algorithm>
using namespace std;

/* devemos verificar se o triangulo eh retangulo usando o teorema de pitagoras */

int main(void) {
	int a, b, c;

	while(scanf(" %d %d %d", &a, &b, &c) && !(a == 0 && b == 0 && c == 0)) {
		if (a < b) {
			swap(a, b);
		}
		if (a < c) {
			swap(a, c);
		}
		printf("%s\n", a * a == b * b + c * c ? "right" : "wrong");
	}
	return 0;
}
	
