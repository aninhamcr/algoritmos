#include <stdio.h>

void merge(int *array, int pos_inicial, int pos_final, int tamanho) {
    int i = 0, i1 = 0, i2 = 0, meio, cursor;
    int temp[tamanho + 1];

    for(i = pos_inicial;i <= pos_final; i++) {
        temp[i] = array[i];
    }

    meio = (pos_inicial + pos_final) / 2;
    i1 = pos_inicial; i2 = meio + 1;

    for(cursor = pos_inicial; cursor <= pos_final; cursor++) {
        if(i1 == meio + 1) {
            array[cursor] = temp[i2];
            i2++;
        }
        else if(i2 > pos_final) {
            array[cursor] = temp[i1];
            i1++;
        }
        else if(temp[i1] <= temp[i2]) {
            array[cursor] = temp[i1];
            i1++;
        }
        else {
            array[cursor] = temp[i2];
            i2++;
        }

    }
}

void mergesort(int *vetor, int pos_inicial, int pos_final, int tamanho) {
    if(pos_inicial < pos_final) {
        int i;

        int meio = (pos_inicial + pos_final) / 2;
        mergesort(vetor, pos_inicial, meio, tamanho);
        mergesort(vetor, meio + 1, pos_final, tamanho);
        merge(vetor, pos_inicial, pos_final, tamanho);
    }
}


int main() {
    int tamanho, i;
    scanf("%d", &tamanho);
    int array[tamanho];

    void mergesort(int vetor[], int pos_inicial, int pos_final, int tamanho);

    for(i=0;i<tamanho;i++) {
        scanf("%d", &array[i]);
    }

    mergesort(array, 0, tamanho - 1, tamanho);

    for(i=0;i<tamanho;i++){
        printf("%d ", array[i]);
    }

    return 0;
}
