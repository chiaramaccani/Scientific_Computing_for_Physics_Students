#include <stdio.h>

int main() {
    int a = 3;
    int x[20];
    int y[20];
    int scalar_product = 0;
    
    // Initialize arrays x and y
    for (int i = 0; i < 20; ++i) {
        x[i] = 1;
        y[i] = 4;
    }
    
    // Calculate scalar product
    for (int i = 0; i < 20; ++i) {
        scalar_product += a * x[i] + y[i];
    }
    
    printf("Scalar product: %d\n", scalar_product);
    
    return 0;
}