#include <stdio.h>
#include <algorithm>
using namespace std;

/* A resposta eh a quantidade comum de letras das duas palavras, ordenadas para obter a 
	menor sequencia lexicografica */

const int MAXN = 1005;

int a[26]; // frequencia de letras da primeira palavra
int b[26]; // frequencia de letras da segunda palavra
char sa[MAXN]; // primeira palavra
char sb[MAXN]; // segunda palavra

int main(void) {
	while(scanf(" %s %s", sa, sb) != EOF) {
		for (int i = 0; i < 26; i++) {
			a[i] = b[i] = 0;
		}
		for (int i = 0; sa[i] != '\0'; i++) {
			int idx = sa[i] - 'a';
			a[idx]++;
		}
		for (int i = 0; sb[i] != '\0'; i++) {
			int idx = sb[i] - 'a';
			b[idx]++;
		}
		for (int i = 0; i < 26; i++) {
			int freq = min(a[i], b[i]); // frequencia da letra i na resposta
			while(freq > 0) {
				printf("%c", i + 'a');
				freq--;
			}
		}
		printf("\n");
	}
	return 0;
}
	
