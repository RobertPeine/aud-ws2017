#include <stdlib.h>
#include <stdio.h>

typedef struct node *tree;
struct node {int key, summe; tree left, right;};

typedef struct element *list;
struct element {int value; list next;};

void append(list *l, int n) {
    if (*l != NULL) {
        append(&(*l)->next, n);
    } else {
        list element = malloc(sizeof(*element));
        element->value = n;
        element->next = NULL;
        
        *l = element;
    }
}

void tree_to_liste(list *l, tree t) {
    if (t == NULL) return;
    
    tree_to_liste(l, t->right);
    append(l, t->key);
    tree_to_liste(l, t->left);
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

void printList(list l) {
    printf("[");
    while(l) {
        printf("%d", l->value);
        if(l->next) printf(", ");
        l = l->next;
    }
    printf("]\n");
}



int main() {
    tree t = cons(8, cons(6, cons(4, NULL, NULL), cons(7, NULL, NULL)), cons(10, cons(9, NULL, NULL), cons(12, NULL, NULL)));
    list l = NULL;
    
    tree_to_liste(&l, t);
    
    printf("t:\n");
    printTree(t, 0);
   
    printf("l: ");
    printList(l);
    
    return 0;
}
