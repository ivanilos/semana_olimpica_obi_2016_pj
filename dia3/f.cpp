#include <stdio.h>
#include <stack>
#define MAXN 1000005
using namespace std;

/* Se considerarmos os parenteses apenas como abrem e fecham, veremos que cada um tem
	seu par. A resposta eh a quantidade desses pares diferentes (mudamos apenas um deles)
	caso a sequencia apenas considerando aberturas e fechamentos seja regular, senao eh 
	impossivel. Isso vale pois soh podemos substituir sinais que abrem por outros que 
	abrem, idem para os que fecham */ 

stack <char> st;
char s[MAXN];
char left[] = {'<', '{', '[', '('};
char right[] = {'>', '}', ']', ')'};

/* Verifica se o caractere c eh um sinal de abertura */
int is_open(char c) {
    for (int i = 0; i < 4; i++) {
        if (c == left[i]) {
            return 1;
        }
    }
    return 0;
}

int main(void) {
    int r = 0;
    int ok = 1;

    scanf(" %s", s);
    for (int i = 0; s[i] != '\0'; i++) {
        if (is_open(s[i])) {
            st.push(s[i]);
        } else {
            if (st.empty()) {
                ok = 0;
            } else {
                char c = st.top();
                st.pop();
                for (int k = 0; k < 4; k++) {
                    if (c == left[k]) {
                        if (s[i] != right[k]) {
                            r++;
                        }
                        break;
                    }
                }
            }
        }
    }
    if (!st.empty()) {
        ok = 0;
    }
    if (ok) {
        printf("%d\n", r);
    } else {
        printf("Impossible\n");
    }
    return 0;
}
