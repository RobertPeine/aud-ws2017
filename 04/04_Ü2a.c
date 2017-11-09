#include <stdio.h> // bindet eine C-Bibliothek ein, die zahlreiche Ein- und Ausgabefunktionen beinhaltet

#define LEN 100 // definiert ein Makro mit dem Namen LEN; beim Kompilieren wird LEN durch 100 ersetzt; kann genutzt werden, um sogenannte "Magic Numbers" im Code zu vermeiden

int main() { // definiert die Funktion main() mit dem Rückgabetyp int (Integer: Ganzzahl)
    char name[LEN]; // C unterstützt keine Strings (Zeichenketten); deshalb wird ein Array definiert, welches LEN einzelne Characters beinhalten kann
    
    printf("Name eingeben: "); // gibt den Text in der Konsole aus
    scanf("%s", &name); // Eingabe wird in Variable name gespeichert
    printf("Hallo %s!\n", name); // gibt den Text in der Konsole aus und ersetzt dabei %s durch den Inhalt der Variable name; %s dient dabei also als Platzhalter
    
    return 0; // main() soll einen Integer-Wert zurückgeben; hier: 0
}
