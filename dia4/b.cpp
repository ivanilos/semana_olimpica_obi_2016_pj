#include <stdio.h>

/* Podemos transformar o valor que temos em segundo e subtrair do valor em segundos de
	24h. Como a quantidade de segundos eh pequena, tambem podemos iterar segundo a segundo
*/

int main(void) {
	int h; // horas
	int m; // minutos
	int s; // segundos

	while(scanf(" %d:%d:%d", &h, &m, &s) != EOF) { // perceba o uso "avancado" de scanf
											// podemos escrever uma expressao regular
											// para o primeiro parametro do scanf
		int t = 60 * 60 * h + 60 * m + s; // segundos passados
		int res = 60 * 60 * 24 - t;
		printf("%d\n", res);
	}
	return 0;
} 
	
