#include <stdio.h>

void solve() {
    long long a, b;
    scanf("%lld%lld", &a, &b);

    printf("%lld\n", a * b);
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
        solve();
}