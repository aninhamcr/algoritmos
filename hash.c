#include <stdlib.h>
#include <stdio.h>
#include <string.h>



typedef struct {
    char chave[16];
    int flag; // se 1 = ocupado, se 0 = vazio, se 2 = deletada
} Entry;


int hash(char *string) { // m = tamanho da tabela de dispersão
    int i = 0, soma = 0;
    for(i=0; string[i] != '\0';i++) {
        soma += (int)string[i]*(i+1);
    }
    soma = soma * 19;
    return abs(soma) % 101;
} 

typedef struct {
    int tam; 
    int q;
    Entry* tabela;

}Dictionary;

Entry cria_entry(char *chave) {
    Entry entrada;
    strcpy(entrada.chave, chave);
    entrada.flag = 1;

    return entrada;
}

Dictionary* cria_dic(int tam) {
    Dictionary *d = (Dictionary*) malloc(sizeof(Dictionary)*101);
    int i;
    d->tam = tam;
    d->q = 0;
    d->tabela = (Entry*) malloc(sizeof(Entry) * tam);
    for(i=0;i<101;i++) {
        d->tabela[i].flag = 0;
    }
    return d;
}

int find(Dictionary *d, char *chave) {
    int index = hash(chave);
    int pos = index;
    int j = 0;

    if(d->tabela[pos].flag == 1 && strcmp(chave, d->tabela[pos].chave) == 0) {
        return pos;
    }
    else {
        while(j<20) {
            j++;
            pos = (index + j*j + 23*j) % 101;
            if(d->tabela[pos].flag == 1 && strcmp(chave, d->tabela[pos].chave) == 0) {
                return pos;
            }
        }
    
        return -1;
        
    }

}


void inserir(Dictionary* d, char* chave) {
    if(d->q < d->tam && find(d, chave) == -1) {
        int h = hash(chave);
        int pos = h;
        int newpos;
        if(d->tabela[pos].flag != 1) {
            Entry entrada = cria_entry(chave);
            d->tabela[pos] = entrada;
            d->q++;
        }
        else {
            int j = 0;
            do {
                j++;
                newpos = (h + j*j + 23*j) % 101; 

            } while(d->tabela[newpos].flag == 1 && j<19);

            if(d->tabela[newpos].flag != 1) {
                Entry entrada = cria_entry(chave);
                d->tabela[newpos] = entrada;
                d->q++;
            }
        }
       
        
    }

}



void remover(Dictionary* d, char* chave) {
    int h = find(d,chave);
    if(h != -1) {
        d->tabela[h].flag = 2;
        strcpy(d->tabela[h].chave, "empty");
        d->q--;
    } 
    else {
        
    }

}

int main() {
    int test, n;
    int lol, i;
    char string[20];
    char *op;
    char *chave;

    scanf("%d", &test);


    for(lol=0;lol<test;lol++) {

        scanf("%d", &n);
        
        Dictionary *dic = cria_dic(101);

        for(i=0;i<n;i++) {
            scanf(" %s", string);
            op = strtok(string,":");
            chave = strtok(NULL,":");
            if(strcmp("ADD", op) == 0) {
            
              inserir(dic, chave);
            }
            else if(strcmp("DEL", op) == 0) {
                remover(dic, chave);
            }
        }

        printf("%d\n", dic->q);

        for(i=0;i<101;i++){
            if(dic->tabela[i].flag == 1) {
                printf("%d:%s\n", i, dic->tabela[i].chave);
            }
        }

        free(dic);

    }

    

    return 0;
}
