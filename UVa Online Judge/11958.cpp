#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve(int test) {
    int busCount, h, m;
    scanf("%d%d:%d", &busCount, &h, &m);
    int t = h * 60 + m;

    int res = 1e9;
    for (int i = 0; i < busCount; i++) {
        int bh, bm, bw;
        scanf("%d:%d%d", &bh, &bm, &bw);
        int bt = bh * 60 + bm;
        if (bt < t)
            bt += 24 * 60;
        res = min(res, bt + bw - t);
    }

    printf("Case %d: %d\n", test, res);
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    scanf("%d", &n);

    for (int test = 1; test <= n; test++)
        solve(test);
}