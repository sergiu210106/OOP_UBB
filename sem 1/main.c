#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

unsigned int* sieve(unsigned int n, int *count) {
    bool* v = (bool*)calloc(n + 1, sizeof(bool));
    if (!v) {
        perror("Memory allocation failed");
        exit(EXIT_FAILURE);
    }

    v[0] = true;
    v[1] = true;

    for (int i = 2; i * i <= n; i++) {
        if (!v[i]) {
            for (int j = i * i; j <= n; j += i) {
                v[j] = true;
            }
        }
    }

    // Count prime numbers
    *count = 0;
    for (int i = 2; i <= n; i++) {
        if (!v[i]) {
            (*count)++;
        }
    }

    // Allocate memory for prime numbers
    unsigned int* result = (unsigned int*)malloc((*count) * sizeof(unsigned int));
    if (!result) {
        perror("Memory allocation failed");
        free(v);
        exit(EXIT_FAILURE);
    }

    // Store prime numbers in the result array
    int length = 0;
    for (int i = 2; i <= n; i++) {
        if (!v[i]) {
            result[length++] = i;
        }
    }

    free(v);
    return result;
}

int main() {
    int count = 0;
    unsigned int* result = sieve(50000, &count);

    for (int i = 0; i < count; i++) {
        printf("%d\n", result[i]);
    }

    free(result);  // Free allocated memory to prevent memory leaks
    return 0;
}
