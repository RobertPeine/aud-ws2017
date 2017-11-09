#include <stdio.h>

// fac_rec, fac_it_1, fac_it_2 und fac_it_3 setzen alle einzeln die Fakultätsfunktion um

// rekursive Funktion
int fac_rec(int n) {
    if (n > 1)
        return n * fac_rec(n-1);
    else
        return 1;
}

// iterative Funktion mit "hochzählender" for-Schleife
int fac_it_1(int n) {
    int result = 1; // definiert eine Variable result vom Typ int, in der wir das Zwischenergebnis speichern, und initialisiert diese mit dem Wert 1
    
    for (int i = 1; i <= n; ++i)
        result *= i; // result *= i ist eine Kurzform für result = result * i
    
    return result;
}

// iterative Funktion mit "runterzählender" for-Schleife
int fac_it_2(int n) {
    int result = 1;
    
    for (int i = n; i > 0; --i)
        result *= i;
    
    return result;
}

// iterative Funktion mit while-Schleife
int fac_it_3(int n) {
    int result = 1, i = 1; // wenn man nur int result, i = 1; schreiben würde, wird die Variable result nicht mit dem Wert 1 initialisiert
    
    while (i <= n) {
        result *= i;
        i++;
    }
    
    return result;
}

int main() {
    int n;
    
    printf("Zahl n eingeben: "); // gibt den Text in der Konsole aus
    scanf("%u", &n); // Eingabe wird in Variable n gespeichert
    
    printf("%u! = %u\n", n, fac_it_1(n)); // gibt den Text in der Konsole aus und ersetzt dabei das erste Vorkommen von %u durch den Inhalt von n und das zweite Vorkommen durch den Rückgabewert des Aufrufs fac_it_1(n) 
    
    return 0;
}
