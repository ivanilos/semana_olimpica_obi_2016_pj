#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;

/* Devemos observar que a resposta eh o maximo entre as distancias verticais e horizontais 
	que o personagem deve percorrer Essa distancia tambem eh conhecida como distancia 
	do rei no xadrez ou distancia de Chebyshev */

int main(void) {
	int x1, y1, x2, y2;
	scanf(" %d %d %d %d", &x1, &y1, &x2, &y2);
	printf("%d\n", max(abs(x1 - x2), abs(y1 - y2)));
	return 0;
}

