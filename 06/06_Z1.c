#include <stdlib.h>
#include <stdio.h>

typedef struct node *tree;
struct node {int key; tree left; tree right;};

void f(int k, int n) {
    for (int m = n - (n % k); m >= 0; m -= k)
        printf("%d ", m);
}


int evenSum(tree t) {
    if (t == NULL) return 0;
    
    return t->key + oddSum(t->left) + oddSum(t->right);
}

int oddSum(tree t) {
    if (t == NULL) return 0;
    
    return evenSum(t->left) + evenSum(t->right);
}


void dechain(tree *t) {
    if (t == NULL || *t == NULL) return;
    
    if ((*t)->left != NULL && (*t)->right == NULL) {
        tree tmp = *t;
        *t = (*t)->left;
        free(tmp);
        dechain(t);
    } else if ((*t)->left == NULL && (*t)->right != NULL) {
        tree tmp = *t;
        *t = (*t)->right;
        free(tmp);
        dechain(t);
    } else {
        dechain(&(*t)->left);
        dechain(&(*t)->right);
    }
}



tree cons(int key, tree l, tree r) {
    tree t = malloc(sizeof(*t));
    t->key = key;
    t->left = l;
    t->right = r;
    return t;
}

void printTree(tree t, int depth) {
    if (t) {
        for (int i = 0; i < depth; i++) printf("\t");
        printf("%d\n", t->key);
        printTree(t->left, depth+1);
        printTree(t->right, depth+1);
    }
}



int main() {
    tree t1 = cons(2, cons(3, cons(1, NULL, NULL), cons(4, NULL, NULL)), cons(5, NULL, NULL));
    tree t2 = cons(2, cons(3, cons(1, NULL, cons(4, NULL, NULL)), NULL), cons(5, cons(6, NULL, NULL), cons(7, NULL, NULL)));
    
    f(3, 7);
    printf("\n");
    printf("evenSum(t1): %d\n", evenSum(t1));
    
    printf("\nt2:\n");
    printTree(t2, 0);
    
    dechain(&t2);
    
    printf("\nt2:\n");
    printTree(t2, 0);
    
    return 0;
}
