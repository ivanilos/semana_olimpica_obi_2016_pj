#include <stdio.h>

/* A definição do problema é a de gcd, então basta acharmos o maior divisor comum
	dos dois valores */

int gcd(int a, int b) {
	if (!b) {
		return a;
	}
	return gcd(b, a % b);
}

int main(void) {
	int n;
	int a, b;

	scanf(" %d", &n);
	while(n--) {
		scanf(" %d %d", &a, &b);
		printf("%d\n", gcd(a, b));
	}
	return 0;
}
	
