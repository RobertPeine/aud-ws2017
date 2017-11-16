#include <stdio.h>

int ack(int x, int y) {
    if (x == 0 && y >= 0) return y + 1;
	if (y == 0 && x > 0) return ack(x-1, 1);
	if (x > 0 && y > 0) return ack(x-1, ack(x, y-1));
}

int main() {
    int x, y;
    
    printf("Zahl x: "); scanf("%d", &x);
    printf("Zahl y: "); scanf("%d", &y);
    
    printf("ack(%d, %d) = %d\n", x, y, ack(x, y));
    
    return 0;
}
