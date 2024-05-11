
#include <stdio.h>
#include <stdlib.h>

typedef struct No{
    int chave;
    int index;
    struct No *left;
    struct No *right;
    int altura;
    int size;
} No;

typedef struct AVL{
    No *root;
} AVL;

No *cria_no(int chave) {
    No *node = (No *) malloc (sizeof(No));
    node->chave = chave;
    node->altura = 0;
    node->left = NULL;
    node->right = NULL;
    node->size = 1;

    return node;
}

AVL *cria_avl() {
    AVL *avl = (AVL *) malloc (sizeof(AVL));
    avl->root = NULL;
    return avl;
}

int altura(No *root) {
    if(root == NULL) {
        return -1;
    }
    return root->altura;

}

int tam(No *root) {
  if (root == NULL) {
    return 0;
  }
  
  return root->size;
}

int getbalance(No *root) {
    if(root == NULL) {
        return 0;
    }
    return altura(root->left) - altura(root->right);
}

int max(int a, int b) {
    if(a > b) {
        return a;
    }
    else {
        return b;
    }
}

No *rightRot(No *root) {
    No *l = root->left;
    No *lr = l->right;

    l->right = root;
    root->left = lr;
    root->altura = max(altura(root->left), altura(root->right)) + 1;
    root->size = 1 + tam(root->left) + tam(root->right);
    l->altura = max(altura(l->left), altura(l->right)) + 1;
    l->size = 1 + tam(l->left) + tam(l->right);

    return l;
}

No *leftRot(No *root) {
    No *r = root->right;
    No *rl = r->left;

    r->left = root;
    root->right = rl;
    root->altura = max(altura(root->left), altura(root->right)) + 1;
    root->size = 1 + tam(root->left) + tam(root->right);
    r->altura = max(altura(r->left), altura(r->right)) + 1;
    r->size = 1 + tam(r->left) + tam(r->right);

    return r;
} 

No *inserthelp(No *root, int chave) {
    if(root == NULL) {
        return cria_no(chave);
    }
    if(root->chave > chave) {
        root->left = inserthelp(root->left, chave);
    }
    else {
        root->right = inserthelp(root->right, chave);
    }
    root->altura = 1 + max(altura(root->left), altura(root->right));
    root->size = 1 + tam(root->left) + tam(root->right);
    int balance = getbalance(root);
   

    if(balance < -1 && chave >= root->right->chave) {
        printf("1");
        return leftRot(root);
    }
    if(balance > 1 && chave < root->left->chave) {
        printf("2");
        return rightRot(root);
    }
    if(balance > 1 && chave >= root->left->chave) {
        printf("3");
        root->left = leftRot(root->left);
        return rightRot(root);

    }
    if(balance < -1 && chave < root->right->chave) {
        printf("4");
        root->right = rightRot(root->right);
        return leftRot(root);
    }

    return root;
}

void insert(AVL *avl, int chave) {
    avl->root = inserthelp(avl->root, chave);
}

int findhelp(No *root, int chave) {
    if(root == NULL) {
        return NULL;
    } 
    if(root->chave > chave) {
        return findhelp(root->left, chave);
    }
    else if(root->chave == chave) {
        return 1;
    }
    else {
        return findhelp(root->right, chave);
    }
}

int find(AVL *arvore, int chave) {
    return findhelp(arvore->root, chave);
}


int rank(No *root, int chave, int temp) { // tail recursive
    if(root == NULL) {
        return temp;
    }

    if(root->chave <= chave && findhelp(root, chave) == 1) {
        if(root->left == NULL) {
            temp = temp + 1;
        }
        else {
            temp = temp + 1 + root->left->size;
        }
        return rank(root->right, chave, temp);
    }
    else {
        return rank(root->left, chave, temp);
    }
}


int main() {

    int i, n;
    scanf("%d", &n);

    AVL *arvore = cria_avl();
    int type, x, index;

    for(i=0;i<n;i++) {
        scanf("%d %d", &type, &x);

        if(type == 1) {
            insert(arvore,x);
        }
        else {
            int temp = 0;
            int p = rank(arvore->root, x, temp);
         //   printf("root = %d", arvore->root->chave);
            if(p == 0) {
                printf("Data tidak ada\n");
            }
            else {
                printf("%d\n", p);
            }
          
        }
    }

    
    

    return 0;
}
