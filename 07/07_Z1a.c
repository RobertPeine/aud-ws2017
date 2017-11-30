#include <stdlib.h>
#include <stdio.h>

typedef struct node *tree;
struct node {int key, summe; tree left, right;};

typedef struct element *list;
struct element {int value; list next;};

int subtree_sum(tree t) {
    if (t == NULL) return 0;
    
    int c = 0;
    if (t->key % 2 == 0) c = t->key;
    
    return c + subtree_sum(t->left) + subtree_sum(t->right);
}

void summen(tree t) {
    if (t == NULL) return;
    
    t->summe = subtree_sum(t);
    
    summen(t->left);
    summen(t->right);
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
        printf("%d: %d\n", t->key, t->summe);
        printTree(t->left, depth+1);
        printTree(t->right, depth+1);
    }
}



int main() {
    tree t = cons(2, cons(3, cons(2, NULL, NULL), cons(4, NULL, NULL)), cons(1, NULL, NULL));
    
    printf("\nt:\n");
    printTree(t, 0);
    
    summen(t);
    
    printf("\nt:\n");
    printTree(t, 0);
    
    return 0;
}
