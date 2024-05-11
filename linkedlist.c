#include <stdlib.h>
#include <stdio.h>

typedef struct link {
    int it;
    struct link *prox;
}Link;

typedef struct {
    Link *head;
    Link *tail;
    Link *curr;
    int cont;
}List;


Link *cria_link(int n, Link *proxval) {
    Link *no = (Link*) malloc(sizeof(Link));
    no->it = n;
    no->prox = proxval;

    return no;
}

List *cria_list() {
    List *list = (List*) malloc(sizeof(List));
    list->curr = list->head = list->tail = cria_link(0,NULL);
    list->cont = 0;
    
    return list;
}

void inserir(List *list, int it) {
    list->curr->prox = cria_link(it, list->curr->prox);
    if(list->tail == list->curr) {
        list->tail = list->curr->prox;
    }
    list->cont++;
}

void next(List *list) {
    if(list->curr != list->tail) {
        list->curr = list->curr->prox;
    }
}

int main() {

    int i, tam, n;
    List *aninha;

    aninha = cria_list();
    scanf(" %d", &tam);

    for(i=0;i<tam;i++) {
        scanf(" %d", &n);
        inserir(aninha, n);
        next(aninha);
    }

    aninha->curr = aninha->head;
    for(i=0;i<tam;i++) {
        next(aninha);
        printf(" %d ", aninha->curr->it);
       
    }

    free(aninha);

    return 0;
}
