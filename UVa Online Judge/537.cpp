#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <cstring>
using namespace std;

pair<char, double> read() {
    char prefix[100000], factor;
    double value;
    scanf("%[^=]=%lf%c", prefix, &value, &factor);
    static map<char, double > factors = { {'m', 1e-3}, {'k', 1e3}, {'M', 1e6} };
    if (factors.count(factor))
        value *= factors[factor];
    return {prefix[strlen(prefix) - 1], value};
}

void solve(int test) {
    auto [p1, v1] = read();
    auto [p2, v2] = read();

    printf("Problem #%d\n", test);
    if (p1 == 'P') {
        if (p2 == 'I')
            printf("U=%.2lfV\n\n", v1 / v2);
        else
            printf("I=%.2lfA\n\n", v1 / v2);
    } else if (p1 == 'I') {
        if (p2 == 'P')
            printf("U=%.2lfV\n\n", v2 / v1);
        else
            printf("P=%.2lfW\n\n", v1 * v2);
    } else {
        if (p2 == 'P')
            printf("I=%.2lfA\n\n", v2 / v1);
        else
            printf("P=%.2lfW\n\n", v1 * v2);
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    scanf("%d", &n);

    for (int test = 1; test <= n; test++)
        solve(test);
}