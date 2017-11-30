#include <stdlib.h>
#include <stdio.h>

typedef struct element *list;
typedef struct element {int value; list next;} element;

int f(list l) {
    while (l && l->next) {
        if (abs(l->value - l->next->value) > 1) return 0;
        l = l->next;
    }
    
    return 1;
}



list cons(int n, list next) {
    list l = malloc(sizeof(*l));
    l->value = n;
    l->next = next;
    return l;
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
    list l1 = cons(3, cons(4, cons(5, cons(6, cons(5, NULL)))));
    list l2 = cons(2, cons(4, cons(1, cons(2, cons(3, NULL)))));
    
    printf("f(l1): %d\n", f(l1));
    printf("f(l2): %d\n", f(l2));
    
    return 0;
}
