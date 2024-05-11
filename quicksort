#include <stdio.h> 


int particionamento(long long *vetor, int pos_inicial, int pos_final) {
    int pivot = vetor[pos_inicial];
    int i = pos_inicial;
    int j = pos_final + 1;
    int temp;

    do {
        do {
            i=i+1;
        }while(vetor[i] < pivot && i < pos_final);

        do {
            j=j-1;
        }while(vetor[j] > pivot);
        temp = vetor[j];
        vetor[j] = vetor[i]; // = swap vetor[i] com vetor[j] !
        vetor[i] = temp;

    }while(i < j);

    temp = vetor[j];
    vetor[j] = vetor[i]; // = swap vetor[i] com vetor[j] !
    vetor[i] = temp;

    temp = vetor[j];
    vetor[j] = vetor[pos_inicial]; // = swap vetor[i] com vetor[j] !
    vetor[pos_inicial] = temp;

    return j; // j = posição final do pivot
}

void quicksort(long long int *vetor, int pos_inicial, int pos_final) {

    if(pos_inicial < pos_final) {
        int s; // s é o índice do pivô
        s = particionamento(vetor, pos_inicial, pos_final);
        quicksort(vetor, pos_inicial, s - 1);
        quicksort(vetor, s + 1, pos_final);
    }
}


int main() {

    int n, i = 0, j = 1, pares, k, aux = 0;
    scanf("%d %d", &n, &k);

    long long int array[n];

    void quicksort(long long int *vetor, int pos_inicial, int pos_final);
    int particionamento(long long int *vetor, int pos_inicial, int pos_final);

    for(i=0;i<n;i++) {
        scanf("%lld", &array[i]);

    }


    quicksort(array, 0, n - 1);

     for(i=0;i<n;i++) {
        printf("%lld --", array[i]);

    }

    while(aux<n - 1) 
    {
        while(array[j] - array[aux] < k) {
        j++;
        }
        if(array[j] - array[aux] == k) {
            pares++;
        }
        aux++;
    }


    printf("%d", pares);

    return 0;
}
