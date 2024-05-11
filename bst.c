#include <stdlib.h>
#include <stdio.h>



typedef struct no {
    int elemento;
    int chave;
    struct no *left;
    struct no *right;
} BSTno;

typedef struct {
    BSTno *root;
    int tam;
} BST; 

BSTno *cria_no(int chave) {
    BSTno *node = (BSTno*) (sizeof(BSTno));
    node->chave = chave;
    node->left = NULL;
    node->right = NULL;

    return node;
}

BST *cria_arvore() {
    BST *arvore = (BST*) malloc(sizeof(BST));
    arvore->root = NULL;
    arvore->tam = 0;

    return arvore;
}

int findhelp(BSTno root, int chave) {
    if(root == NULL) {
        return NULL;
    } 
    if(root.chave > chave) {
        return findhelp(root.left, chave);
    }
    else if(root.chave == chave) {
        return root.elemento;
    }
    else {
        return findhelp(root.right, chave);
    }
}

int find(BST arvore, int chave) {
    return findhelp(arvore.root, chave);
}

BSTno *inserthelp(BSTno root, int chave) {
    if(root == NULL) {
        return cria_no(chave);
    }
    if(root.chave > chave) {
        root.left = inserthelp(root.left, chave);
    }
    else {
        root.right = inserthelp(root.right, chave);
    }

    return root;
}

void *insert(BST *arvore, int chave) {
    arvore->root = inserthelp(arvore->root, chave);
    arvore->tam++;
}

void preorder(BSTno root) {
    if(root != NULL) {
        printf("%d ", &root.chave);
        preorder(root.left);
        preorder(root.right);
    }
}

void inoder(BSTno root) {
    if(root != NULL) {
        inoder(root.left);
        printf("%d ", &root.chave);
        inoder(root.right);
    }
}

void posorder(BSTno root) {
    if(root != NULL) {
        posorder(root.left);
        posorder(root.right);
        printf("%d ", &root.chave);
    }
}


int main() {

    return 0;
}
