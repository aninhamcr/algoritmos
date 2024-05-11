#include <iostream>
#include <list>
#include <vector>
#include <queue> 
#include <limits>
#include <tuple>

using namespace std;

enum MARK {
    UNVISITED, VISITED, CLOSED
};

struct link{
    int it;
    int peso;
};

struct Grafo {
    vector<list<link>> grafo;
    int arestas;
    int nos;
    vector<int> marcados;
};

Grafo* cria_grafo(int n) {
    Grafo *g = new Grafo;
    g->grafo.resize(n);
    g->marcados.resize(n, UNVISITED);
    g->arestas = 0;
    g->nos = n;

    return g;
}


void setMark(Grafo* g, int v, MARK marca) {
    g->marcados[v] = marca;
}

int getMark(Grafo* g, int v) {
    return g->marcados[v];
}

int first(Grafo* g, int v) {
    if(!g->grafo[v].empty()) {
        link temp = g->grafo[v].front();
        return temp.it;
    }
    return g->nos;
}

int next(Grafo* g, int v, int w) {
  list<link>::iterator it;
  for (it = g->grafo[v].begin(); it != g->grafo[v].end(); ++it) {
    if ((*it).it == w) {
      while (++it != g->grafo[v].end()){
        if(getMark(g,(*it).it) == UNVISITED) {
          return (*it).it;
        }
      }
      break;
    }
  }

  return g->nos;
}


void setEdge(Grafo* g, int i, int j, int peso) {
    link link;
    link.it = j;
    link.peso = peso;
    g->grafo[i].push_back(link);
    g->arestas++;
} 

void delEdge(Grafo* g, int i, int j) {
    int m;
    list<link>::iterator iterador;
    iterador = g->grafo[i].begin();

    for(m=0;m < g->grafo[i].size();m++) {
        if((*iterador).it == j) {
            g->grafo[i].erase(iterador);
        }
        iterador++;
    }
    g->arestas--;
}

int getEdge(Grafo* g, int i, int j) {
    int m;
    list<link>::iterator iterador;
    iterador = g->grafo[i].begin();

    for(m=0;m < g->grafo[i].size();m++) {
        if((*iterador).it == j) {
            return (*iterador).peso;
        }
        iterador++;
    }
    return -1;
}

vector<int> Dijkstra(Grafo* g, int origem, vector<int>&caminho) {
    int i;
    vector<int> parent;
    parent.resize(g->nos);
    for(i=0;i< g->nos;i++) {
        g->marcados[i] = UNVISITED;
    }
    caminho.resize(g->nos, numeric_limits<int>::max());

    priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, greater<tuple<int,int,int>>> fila;

    fila.push(make_tuple(0,origem,origem));
    caminho[origem] = 0;

    int p,v;

    for(i=0;i < g->nos;i++) {
        do {
            if(fila.empty()) {
                return caminho; 
            }
            tuple<int,int,int> temp = fila.top();
            fila.pop();
            p = get<1>(temp);
            v = get<2>(temp);


        } while(getMark(g,v) == VISITED );
        setMark(g,v,VISITED);
        parent[v] = p;

        int w;
        link valor;
        for (link valor : g->grafo[v]) {
            w = valor.it;
            int peso = getEdge(g,v,w);
            if(getMark(g,w) != VISITED && caminho[w] > caminho[v] + peso) {
                caminho[w] = caminho[v] + peso;
                fila.push(make_tuple(caminho[w],v,w));
            }
        }
        
    }

    return caminho;
}



int main() {
    
    int cases, n, m, s, t;
    int i,j;
    int v1,v2,peso;

    cin >> cases;
    for(i=0;i<cases;i++) {
        cin >> n >> m >> s >> t;

        Grafo* grafo = cria_grafo(n);

        for(j=0;j<m;j++) {
            cin >> v1 >> v2 >> peso;
            setEdge(grafo, v1, v2, peso);
        }

        vector<int> distancia;
        Dijkstra(grafo, s, distancia);
       
        if(distancia[t] < numeric_limits<int>::max()) {
            cout << "Case #" << i+1 << ":" << distancia[t] << endl;
        }
        else {
            cout << "Case #" << i+1 << ":unreachable" << endl;
        }

    }


    return 0;
}
