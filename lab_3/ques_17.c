#include <stdio.h>

int main() {
    int m, n, sum = 0;

    printf("Enter the value of m: ");
    scanf("%d", &m);

    printf("Enter the value of n: ");
    scanf("%d", &n);

    // Edge Case Protection: If m is greater than n, swap them!
    if (m > n) {
        int temp = m;
        m = n;
        n = temp;
    }

    for(int i = m; i <= n; i++) {
        sum += i;
    }

    printf("\nThe sum of numbers from %d to %d is: %d\n", m, n, sum);

    return 0;
}