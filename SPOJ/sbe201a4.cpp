#include <stdio.h>

int solve() {
    int size;
    scanf("%d", &size);

    if (!size)
        return 0;

    int minValue = 2e9;
    for (int i = 0; i < size; i++) {
        int value;
        scanf("%d", &value);

        if (minValue > value)
            minValue = value;
    }

    printf("%d\n", minValue);
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}