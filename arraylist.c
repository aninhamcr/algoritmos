#include <stdlib.h>
#include <stdio.h>


typedef struct {
    int tam_max;
    int tam_list;
    int cursor;
    int *vetor;
} List;

List* create_list(int tamanho) {
    List* l = (List*) malloc(sizeof(List));
    l->tam_max = tamanho;
    l->tam_list = 0;
    l->cursor = 0;
   // int array[tamanho];
    l->vetor = malloc(sizeof(int) * tamanho);
    return l;
}

void inserir(List *l, int n) {
    if(l->tam_list >= l->tam_max) {
        exit(1);
    }
    else {
        int i = l->tam_list;
        while(i > l->cursor) {
            l->vetor[i] = l->vetor[i - 1];
            i--;
        }
        l->vetor[l->cursor] = n;
        l->tam_list++;
    }
}

void inicio(List *l) {
    l->cursor = 0;
}

void final(List *l) {
    l->cursor = l->tam_list;
}

void anterior(List *l) {
    if(l->cursor != 0) {
        l->cursor++;
    }
}

void next(List *l) {
    if(l->cursor < l->tam_list) {
        l->cursor++;
    }
}

int remover(List *l) {
    if(l->cursor < 0 || l->cursor >= l->tam_list) {
        return NULL;
    }
    int it = l->vetor[l->cursor];
    int i = l->cursor;
    while(i < l->tam_list - 1) {
        l->vetor[i] = l->vetor[i + 1];
        i++;
    }
    l->tam_list--;
    return it;
}

int main() {

    //List* create_list(int tamanho);4

    int i, n;
    int tam = 4;

    List *aninha = create_list(tam);

    for(i=0;i<tam;i++){
        scanf("%d", &n);
        inserir(aninha, n);
        final(aninha);
    } 

    for(i=0;i<tam;i++){
        printf("%d ", aninha->vetor[i]);
    } 

    free(aninha);

    return 0;
}
