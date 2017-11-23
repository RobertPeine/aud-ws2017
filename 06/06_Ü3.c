#include <stdlib.h>
#include <stdio.h>

typedef struct node *tree;
typedef struct node {int key; tree left; tree right;} node;

int count(tree t, int k) {
    if (t == NULL) return 0;
    
    int c = 0;
    if (t->key == k) c = 1;
    
    return c + count(t->left, k) + count(t->right, k);
}

tree baz(tree s, tree t) {
    if (s == NULL) return NULL;
    
    tree result = malloc(sizeof(*result));
    result->key = count(t, s->key);
    result->left = baz(s->left, t);
    result->right = baz(s->right, t);
    
    return result;
}


int leafprod(tree t) {
    if (t == NULL) return 1;
    
    if (t->left == NULL && t->right == NULL)
        return t->key;
    
    return leafprod(t->left) * leafprod(t->right);
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
    tree t = cons(2, cons(3, cons(2, NULL, NULL), cons(4, NULL, NULL)), cons(1, NULL, NULL));
    tree s = cons(2, cons(2, NULL, NULL), cons(3, NULL, NULL));
    
    printf("leafprod(t): %d\n", leafprod(t));
    printf("leafprod(s): %d\n", leafprod(s));
    
    printf("\nt:\n");
    printTree(t, 0);
    
    printf("\ns:\n");
    printTree(s, 0);
    
    tree x = baz(t, s);
    printf("\nbaz(t, s):\n");
    printTree(x, 0);
    
    return 0;
}
