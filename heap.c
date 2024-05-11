#include <stdlib.h>
#include <stdio.h>

void cria_bttmup(int *vetor, int tam) {
    int i;
    for(i=tam/2;i>=1;i--) {
        int k = i;
        int v = vetor[k];
        int flag = 0;

        while(flag == 0 && 2*k <= tam) {
            int j = 2*k;
            if(j<tam) {
                if(vetor[j] < vetor[j+1]) {
                    j = j + 1;
                }
            }
            if(v >= vetor[j]) {
                flag = 1;
              //  printf("oi");
            }
            else {
                vetor[k] = vetor[j];
                k = j;
            }
        }
        vetor[k] = v;
    }
}

void heapfy(int *vetor, int tam) {
    int i=1;
        int k = i;
        int v = vetor[k];
        int flag = 0;

        while(flag == 0 && 2*k <= tam) {
            int j = 2*k;
            if(j<tam) {
                if(vetor[j] < vetor[j+1]) {
                    j = j + 1;
                }
            }
            if(v >= vetor[j]) {
                flag = 1;
              //  printf("oi");
            }
            else {
                vetor[k] = vetor[j];
                k = j;
            }
        }
        vetor[k] = v;
    
}

int remove_topo(int *vetor, int *tam) {
    int temp, i;

    temp = vetor[1];
    vetor[1] = vetor[*tam];
    vetor[*tam] = temp;
    (*tam)--;

    heapfy(vetor, *tam);

    return abs(temp);

}

int main() {
    int n;
    while(scanf("%d", &n) != 0 && n !=0 ) {
        int i, lol;
        int *vetor = (int*) malloc((n + 1) * sizeof(int));

        for(i=1;i<=n;i++) {
            scanf("%d", &lol);
            vetor[i] = lol * -1;
        }

        int aux = n;

        cria_bttmup(vetor,n);

        int soma=0;
    
        for(i=1;i<aux;i++) {
            
            int custo1, custo2, c3;
            custo1 = remove_topo(vetor,&n);
            custo2 = remove_topo(vetor,&n);
    
            c3 = custo1 + custo2;
           
          //  printf("custo, %d + %d = %d\n", custo1, custo2, c3);
            soma += c3;
         //   printf("soma1 = %d\n", soma);

            vetor = (int *) realloc(vetor, sizeof(int)*(n+2));
            n++;
            vetor[n] = c3*-1;
            cria_bttmup(vetor, n);

            int j; 
        //    for(j=1;j<=n;j++) {
        //        printf("-> %d ", abs(vetor[j]));
         //   }
         //   printf("\n");
            
    
        }

        printf("%d", soma);
        free(vetor);
      
    }

    return 0;
}
