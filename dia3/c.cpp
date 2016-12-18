#include <stdio.h>
#define INF 0x3f3f3f3f

/* A solucao eh por busca binaria na resposta. Se chutarmos um valor da altura maxima, 
	podemos verificar pelo PIE (principio de inclusao exclusao) quantas torres podemos
	formar com peças de 2 blocos e peças de 3 blocos - se conseguirmos para altura maxima 
	igual a x, tambem conseguimos para altura maxima igual a x + 1. */

int main(void) {
    int n, m;

    scanf(" %d %d", &n, &m);
    int low = 0;
    int high = INF;
    int best = INF; // resposta
    while(low <= high) {
        int mid = (low + high) / 2; 
        int two = mid / 2; // numero de torres possiveis com peças de 2 blocos
        int three = mid / 3;  // numero de torres possiveis com peças de 3 blocos
        int six = mid / 6; // numero de torres possiveis com peças de 6 blocos

        if (three >= m && two >= n && two + three - six >= n + m) {
            best = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    printf("%d\n", best);
    return 0;
}
	
