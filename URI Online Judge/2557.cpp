#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    char a[10], b[10], c[10];
    if (scanf(" %[^+]+%[^=]=%s", a, b, c) == EOF)
        return 0;

    if (isalpha(a[0]))
        printf("%d\n", atoi(c) - atoi(b));
    else if (isalpha(b[0]))
        printf("%d\n", atoi(c) - atoi(a));
    else
        printf("%d\n", atoi(a) + atoi(b));
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}