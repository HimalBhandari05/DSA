#include <stdio.h>

#define MAX 100
int table[MAX] = {0};

int fibo(int n) {
    if (n == 1 || n == 2) {
        return 1;
    }   
    if (table[n] != 0) {
        return table[n];
    }
    table[n] = fibo(n - 1) + fibo(n - 2);    // Store the result in the table
    return table[n];
}

int main() {
    int n;
    printf("Enter n: ");
    scanf("%d", &n);
    printf("Fibonacci(%d) = %d\n", n, fibo(n));
    return 0;
}