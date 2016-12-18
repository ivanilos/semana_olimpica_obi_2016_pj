#include <stdio.h>
#include <math.h>

/* No pior caso da guarda costeira alcançar o fugitivo, ela fara isso depois que o fugitivo
	tiver percorrido 12 km, assim, se ela chega nesse ponto antes do fugitivo ela consegue
	capturar ele */

/* ----------------------------------
				|\
			    | \   x
            12  |  \
                |   \
                |    \
------------------------------------
                   D

A distancia percorrida pela guarda costeira x, e dado pelo teorema de pitagoras,
conforme figura

*/

const double EPS = 1e-6; // um numero bem pequeno

int main(void) {
	int d, vf, vg;

	while(scanf(" %d %d %d", &d, &vf, &vg) != EOF) {
		double x = sqrt(12 * 12 + d * d);
		double tf = 12.0 / vf; // tempo gasto pelo fugitivo
		double tg = x / vg; // tempo gasto pela guarda costeira
		if (tg <= tf + EPS) { // comparacao de double, devemos usar EPS
			printf("S\n");
		} else {
			printf("N\n");
		}
	}
	return 0;
}
		
