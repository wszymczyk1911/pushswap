#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int n = 100;
    int a[100];

    // Sorted array
    for (int i = 0; i < n; i++)
        a[i] = i + 1;

    int targetInversions = 990;   // 0.2 disorder
    int inversions = 0;

    srand(time(NULL));

    while (inversions < targetInversions) {
        int i = rand() % (n - 1);

        // Only swap if it creates a new inversion
        if (a[i] < a[i + 1]) {
            int temp = a[i];
            a[i] = a[i + 1];
            a[i + 1] = temp;
            inversions++;
        }
    }

    // Print permutation
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);

    printf("\n");
    return 0;
}
