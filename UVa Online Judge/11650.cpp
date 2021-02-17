#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    int h, m;
    scanf("%d:%d", &h, &m);

    if (h != 12)
        h = 12 - h;
    if (m != 0) {
        m = 60 - m;
        if (--h == 0)
            h = 12;
    }

    printf("%02d:%02d\n", h, m);
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
        solve();
}