#include <stdlib.h>
#include <stdio.h>

typedef struct list_ele *list;
typedef struct list_ele {int key; list next;} l_ele_type;

void delete_n(list *l, int n) {
    if (*l == NULL) return;
    
    if ((*l)->key == n) {
        *l = (*l)->next;
        delete_n(l, n);
    } else {
        delete_n(&(*l)->next, n);
    }
}


int ordered_rec(list l) {
    if (l == NULL || l->next == NULL) return 1;
    
    return (l->key <= l->next->key) && ordered_rec(l->next);
}

int ordered_it(list l) {
    int result = 1;
    
    while (l != NULL && l->next != NULL) {
        result = result && (l->key <= l->next->key);
        l = l->next;
    }
    
    return result;
}



list cons(int n, list next) {
    list l = malloc(sizeof(*l));
    l->key = n;
    l->next = next;
    return l;
}

void printList(list l) {
    printf("[");
    while(l) {
        printf("%d", l->key);
        if(l->next) printf(", ");
        l = l->next;
    }
    printf("]\n");
}



int main() {
    list l = cons(1, cons(5, cons(3, cons(5, cons(7, NULL)))));
    
    printf("l: ");
    printList(l);
    printf("ordered_rec(l): %d\n", ordered_rec(l));
    printf("ordered_it(l): %d\n", ordered_it(l));
    
    delete_n(&l, 5);
    
    printf("l: ");
    printList(l);
    printf("ordered_rec(l): %d\n", ordered_rec(l));
    printf("ordered_it(l): %d\n", ordered_it(l));
    
    return 0;
}
