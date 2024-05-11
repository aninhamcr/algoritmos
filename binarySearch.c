#include <stdio.h>
#include <string.h>

typedef struct {
    char nome[30];
}lista1;


int binarysearch(lista1 *vetor, int pos_inicial, int pos_final, char *k) {
    if(pos_final >= pos_inicial) {
        int m = (pos_inicial + pos_final) / 2;
        if(strcmp(k, vetor[m].nome) == 0) {
            return m;
        }
        else if(strcmp(k, vetor[m].nome) == -1){
            return binarysearch(vetor, pos_inicial, m - 1, k);
        }
        else {
            return binarysearch(vetor, m + 1, pos_final, k);
        }
    }
    else {
        return -1;
    }
}


int main() {
    int e, i, q;
    char k[30];

    scanf("%d", &e);
    lista1 estudantes[e];
    for(i=0;i<e;i++) {
        scanf("%s[^\n]", estudantes[i].nome);
    }

    scanf("%d", &q);

    int binarysearch(lista1 *vetor, int pos_inicial, int pos_final, char *k);

    for(i=0;i<q;i++) {
        scanf("%s[^\n]", k);
        int pos = binarysearch(estudantes, 0, e - 1, k);
        if(pos != -1) {
            printf("+\n");
        }
        else {
            printf("-\n");
        }
    }

    return 0;
}



    for(i=0;i<n-1;i++) {
        for(j=i+1;j<i+k;j++) {
            if(array[j] - array[i] == k) {
                pares += 1;
            }
        }

    }
