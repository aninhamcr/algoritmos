
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct {
    char* chave;
    int flag; // se 1 = ocupado, se 0 = vazio
} Entry;

int hash(char *string) { // hash function ; m = tamanho da tabela de dispersão 
    int i, soma;
    for(i=0; string[i] != '\0';i++) {
        soma += (string[i])*(i+1);
    }
    soma = soma * 19;
    return abs(soma) % 101;
}

typedef struct {
    int tam; 
    int q;
    Entry* tabela;

}Dictionary;

Dictionary* cria_dic(int tam) {
    Dictionary *d;
    d->tam = tam;
    d->q = 0;
    d->tabela = (Entry*) malloc(sizeof(Entry) * tam);
    return d;
}

int find(Dictionary *d, char *chave) {
    int index = hash(chave);
    int pos = index;
    int j;
    while(j<20 && d->tabela[pos].flag != 1 ) {
        pos = (index + j*j + 23*j) % 101;
    }

    if(d->tabela[pos].flag == 1) {
        return 1;
    }
    else {
        return 0;
    }

}


void inserir(Dictionary* d, char* chave) {
    if(d->q < d->tam && find(d, chave) == 0) {
        int h = hash(chave);
        int pos = h;
        int newpos;
        if(d->tabela[pos] != NULL && d->tabela[pos].flag != 0) {
            int j = 0;
            do {
                newpos = (h + j*j + 23*j) % 101; 

            } while(d->tabela[newpos] != NULL && d->tabela[newpos].flag == 1 && j<20);
        }
    }
}


void remover(Dictionary* d, char* chave) {
    if(find(d, chave) == 1) {
        int h = hash(chave);
        d->tabela[h].flag = 0;
        strcpy(d->tabela[h].chave, "empty");

    } 

}

int main() {
    int test, n;
    scanf("%d %d", &test, &n);
    int i, j;
    char* operacao;
    char* chave;

    Dictionary *dic = cria_dic(101);

    for(i=0;i<n;i++) {
        for(j=0;j<4;j++) {
            scanf(" %c", &operacao[j]);
        }
        for(j=4;j!='\n';j++) {
            scanf(" %c", &chave[j-4]);
        }
        if(strcmp("ADD:", operacao) == 0) {
            inserir(dic, chave);
        }
        else if(strcmp("DEL:", operacao) == 0) {
            remover(dic, chave);
        }
    }

    printf("%d", dic->q);

    return 0;
}
