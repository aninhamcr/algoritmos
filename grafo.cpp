#include <iostream>
#include <vector>
#include <list>
#include <cstdio>

using namespace std;

typedef struct grafo {
    vector<vector<int>> no;
    int arestas;
    int nos;
    vector<int> marcados;
    vector<int> pai;
} Grafo;

typedef struct link {
    int it;
    struct link *prox;
}Link;

typedef struct {
    Link *top;
    int size;
}Stack;


Grafo* cria_grafo(int n) {
    Grafo *g = new Grafo;
    g->marcados.resize(n,0);
    g->arestas = 0;
    g->no.resize(n);
    g->nos = n;

    return g;
}

Link *cria_link(int n, Link *proxval) {
    Link *no = (Link*) malloc(sizeof(Link));
    no->it = n;
    no->prox = proxval;

    return no;
}

Stack *cria_pilha() {
    Stack *pilha = (Stack *) malloc(sizeof(Stack));
    pilha->top = NULL;
    pilha->size = 0;

    return pilha;
}

void push(Stack *pilha, int it) { // add coisa na pilha
    pilha->top = cria_link(it, pilha->top);
    pilha->size++;
}

int pop(Stack *pilha) { // tira da pilha e retorna o que tirou
    int n;
    if(pilha->top == NULL) {
        exit(1);
    }
    n = pilha->top->it;
    pilha->top = pilha->top->prox;
    pilha->size--;

    return n;
}

int first(Grafo* g, int v) {
    if(!g->no[v].empty()) {
        return g->no[v][0];
    }
    return g->nos;
}

int next(Grafo* g, int v, int w){
    int i;
    for(i=0;i < g->nos ;i++) {
        if(g->no[v][i] == w && i+1 < g->no[v].size()) {
            return g->no[v][i+1];
        }
    }
    return g->nos;
}

void setMark(Grafo* g, int v, int marca) {
    g->marcados[v] = marca;
}

int getMark(Grafo* g, int v) {
    return g->marcados[v];
}

int dfsSort(Grafo* g, int v, Stack* pilha) {
    g->marcados[v] = 1;

    for(int j=0; j < g->no[v].size() ;j++) {
        int temp = g->no[v][j];
        if(g->marcados[temp] == 0) {
            dfsSort(g,temp,pilha);
        }
        else if(g->marcados[temp] == 1){
            return -1;
        }

       
    }
    g->marcados[v] = 2;
    push(pilha,v);

    return 0;
}

void toposortDFS(Grafo* g, Stack* pilha ) { 
    int i;
    for(i=0;i<g->nos;i++) {
        g->marcados[i] = 0;
    }
    int condicao = 0;

    for(i=0;i<g->nos;i++) {
        if(g->marcados[i] == 0) {
            condicao += dfsSort(g,i,pilha);
        }
    }

    if(condicao < 0){
        printf("ciclo\n");
    }
    else {
        for(i=0;i<g->nos;i++) {
            pop(pilha);
        }
    }

}

int main() {
    int i,n,m,x,y;
    Stack *pilha;
    pilha = cria_pilha();

    scanf("%d %d", &n, &m);

    Grafo* g;
    g = cria_grafo(n);

    for(i=0;i<m;i++) {
        scanf("%d %d", &x, &y);
        g->no[x].push_back(y);
    }
    
    toposortDFS(g,pilha);

    delete g;
    free(pilha);

    return 0;
}
