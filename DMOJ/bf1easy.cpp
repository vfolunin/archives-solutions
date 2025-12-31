#include <stdio.h>

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int size;
    scanf("%d", &size);

    for (int i = 1; i <= size; i++)
        printf("%d ", i);
}