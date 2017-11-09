#include <stdio.h>

#define LEN 1001 // definiert ein Makro mit dem Namen LEN; beim Kompilieren wird LEN durch 1001 ersetzt; kann genutzt werden, um sogenannte "Magic Numbers" im Code zu vermeiden

int main() {
    // zur Bestimmung der Primzahlen nutzen wir das "Sieb des Eratosthenes"
    
    int sieve[LEN]; // definiert ein Array, welches LEN einzelne Integer-Werte beinhalten kann
        
    // 0 und 1 sind keine Primzahlen
    sieve[0] = 0, sieve[1] = 0;
    
    // markiere alle Zahlen >= 2 als potentielle Primzahlen mit 1
    for (int i = 2; i < LEN; ++i)
        sieve[i] = 1;
    
    for (int i = 2; i < LEN; ++i) {
        if (sieve[i] != 0) { // prüft, ob i eine Primzahl ist
            printf("%d\n", i); // gibt i aus, da sieve[i] != 0 gilt und demnach i eine Primzahl ist
            
            // streiche die Vielfachen von i (da diese keine Primzahlen sein können), beginnend bei j = i * 2, indem sieve[j] = 0 gesetzt wird; j wird nach jedem Durchlauf um i erhöht
            for (int j = i * 2; j < LEN; j += i) // j += i ist eine Kurzform für j = j + i
                sieve[j] = 0;
        }
    }
    
    return 0;
}
