#include <stdlib.h>
#include <stdio.h>

typedef struct node *tree;
typedef struct node {int key; tree left, right;} node;

void defol(tree *p) {
    if (p == NULL || *p == NULL) return;
    
    if ((*p)->left == NULL && (*p)->right == NULL) {
        free(*p);
        *p = NULL;
    } else {
        defol(&(*p)->left);
        defol(&(*p)->right);
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
    tree t = cons(2, cons(3, cons(2, NULL, NULL), cons(4, NULL, NULL)), cons(1, NULL, NULL));
    
    printf("\nt:\n");
    printTree(t, 0);
    
    defol(&t);
    
    printf("\nt:\n");
    printTree(t, 0);
    
    return 0;
}
