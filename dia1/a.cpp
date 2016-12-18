#include <stdio.h>
#include <stdlib.h>

/* Um argumento guloso indica que devemos parear a maior habilidade com a menor
Tambem eh possivel testar todas as possibilidades e pegar a menor */

int main(void) {
	int a, b, c, d;

	scanf(" %d %d %d %d", &a, &b, &c, &d);
	printf("%d\n", abs((a + d) - (b + c)));
	return 0;
}
