#include <stdio.h>

int main() {
    int total, factor, amount;
    
    printf("Betrag: ");
    scanf("%u", &total);
    
    factor = 500;
    
    while (total != 0) {
        amount = total / factor;
        
        if (amount > 0)
            printf("%u x %u\n", amount, factor);
        
        total = total % factor;
        
        switch (factor) {
            case 500: factor = 200; break;
            case 200: factor = 100; break;
            case 100: factor = 50; break;
            case 50: factor = 20; break;
            case 20: factor = 10; break;
            case 10: factor = 5; break;
            case 5: factor = 2; break;
            case 2: factor = 1; break;
        }
    }
    
    return 0;
}
