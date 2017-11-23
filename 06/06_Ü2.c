#include <stdlib.h>
#include <stdio.h>

typedef struct element *list;
struct element {int value; list next;};

int sum_rec(list l) {
    if (l == NULL) return 0;
    
    return l->value + sum_rec(l->next); // l->value ist eine Kurzform für (*l).value
}

int sum_it(list l) {
    int result = 0;
    
    while (l != NULL) {
        result += l->value;
        l = l->next;
    }
    
    return result;
}


void rmEvens_rec(list *lp) {
    if (lp == NULL || *lp == NULL) return;
    
    if ((*lp)->value % 2 == 0) {
        list tmp = *lp;
        *lp = (*lp)->next;
        free(tmp);
    } else {
        lp = &(*lp)->next;
    }
    
    rmEvens_rec(lp);
}

void rmEvens_it(list *lp) {
    while (lp != NULL && *lp != NULL) {
        if ((*lp)->value % 2 == 0) {
            list tmp = *lp;
            *lp = (*lp)->next;
            free(tmp);
        } else {
            lp = &(*lp)->next;
        }
    }
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
    list l = cons(3, cons(6, cons(2, cons(1, cons(4, NULL)))));
    
    printf("sum_rec(l): %d\n", sum_rec(l));
    printf("sum_it(l): %d\n\n", sum_it(l));
    
    printf("l: ");
    printList(l);
    rmEvens_rec(&l);
    printf("l: ");
    printList(l);
    
    return 0;
}
