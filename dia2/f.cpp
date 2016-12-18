#include <stdio.h>
#include <algorithm>
using namespace std;

/* Podemos considerar todas as janelas de tamanho N - K e calcular o minimo desses valores*/
 
const int MAXN = (int)1e5 + 5;
 
int v[MAXN];
 
int main(void) {
    int n, k;
 
    scanf(" %d %d", &n, &k);
    for (int i = 0; i < n; i++) {
        scanf(" %d", &v[i]);
    }
    sort(v, v + n);
 
    int res = v[n - 1] - v[0];
    for (int i = k, j = n - 1; i >= 0; i--, j--) {
        res = min(res, v[j] - v[i]);
    }
    printf("%d\n", res);
    return 0;
}
