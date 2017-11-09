#include <stdio.h>

int main() {
    int n; // definiert eine Variable n vom Typ int (Integer: Ganzzahl)
    
    printf("Zahl n eingeben: "); // gibt den Text in der Konsole aus
    scanf("%d", &n); // Eingabe wird in Variable n gespeichert
    
    for (int i = 1; i <= n; ++i) { // Schleife durchläuft Zeilen beginnend mit i = 1, solange i <= n gilt und erhöht nach jedem Durchlauf i um 1; ++i ist eine Kurzform für i = i + 1
        for (int j = 1; j <= n; ++j) { // Schleife durchläuft Spalten
            printf("%d\t", i * j); // Ausgabe der Multiplikation von aktueller Zeilenzahl i mit Spaltenzahl j und Tabulator \t
        }
        
        printf("\n"); // Ausgabe eines Zeilenumbruchs \n
    }
    
    return 0;
}
