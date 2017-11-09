#include <stdio.h>
#include <stdlib.h>

int main() {
    int guess, number, n, tries = 1;
    
    printf("Maximale Zahl: ");
    scanf("%u", &n);
    
    srand(time(NULL));
    number = 1 + rand() % n;
    
    while (1) {
        printf("Zahl zwischen 1 und %u raten: ", n);
        scanf("%u", &guess);
        
        if (guess == number) {
            printf("Korrekt! Benötigte Versuche: %u\n", tries);
            return 0;
        } else if (guess > number) {
            printf("Zahl ist kleiner.\n");
        } else {
            printf("Zahl ist größer.\n");
        }
        
        tries++;
    }
    
    return 0;
}
