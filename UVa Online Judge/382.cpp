#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <string>
using namespace std;

bool solve() {
    int n;
    scanf("%d", &n);
    if (!n)
        return 0;

    int sum = 0;
    for (int i = 1; i < n; i++)
        if (n % i == 0)
            sum += i;

    printf("%5d  ", n);
    if (n < sum)
        printf("ABUNDANT\n");
    else if (n > sum)
        printf("DEFICIENT\n");
    else
        printf("PERFECT\n");
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    printf("PERFECTION OUTPUT\n");
    while (solve());
    printf("END OF OUTPUT\n");
}