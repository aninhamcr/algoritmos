#include <iostream>
#include <vector>
#include <algorithm> 

using namespace std;

int mochila(int n, int peso, vector<int>& w, vector<int>& valor, vector<vector<int>>& matriz) {
    int temp;    
    if(matriz[n][peso] < 0)  {
        if(peso < w[n]) {
            temp = mochila(n-1,peso,w,valor,matriz);
        }
        else {
            temp = max(mochila(n-1,peso,w,valor,matriz), valor[n] + mochila(n-1,peso-w[n],w,valor,matriz));
        }

        matriz[n][peso] = temp;
    } 
    
    return matriz[n][peso];
}


int main() {
    int n, peso, i;
    vector<int> w;
    vector<int> value;

    cin >> peso >> n;

    w.resize(n+1);
    value.resize(n+1);
    vector<vector<int>> matriz(n+1, vector<int>(peso+1, -1));
    
    for(i=0;i<=peso;i++) {
        matriz[0][i] = 0;
    }
    for(i=0;i<=n;i++) {
        matriz[i][0] = 0;
    }

    for(i=0;i<n;i++) {
        cin >> w[i+1] >> value[i+1];
    }

    int best = mochila(n,peso,w,value,matriz);
    cout << best << endl; 

    return 0;
}
