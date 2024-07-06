#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int divl(int a, int b) {
    return a >= 0 ? a / b : (a - b + 1) / b;
}

int divr(int a, int b) {
    return a >= 0 ? (a + b - 1) / b : a / b;
}

void solve(int test) {
    int al, ar, bl, br, modl, modr;
    cin >> al >> ar >> bl >> br >> modl >> modr;

    int res = 0;
    for (int a = al; a <= ar; a++) {
        for (int mod = modl; mod <= modr; mod++) {
            int l = divr(bl, mod), r = divl(br, mod);
            if (l <= r)
                res += r - l + 1;

            if (mod % 2 == 0) {
                int l = divr(bl - mod / 2, mod), r = divl(br + mod / 2, mod);
                if (l <= r)
                    res += r - l;
            }
        }
    }

    cout << "Case " << test << ": " << res << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for (int test = 1; test <= n; test++)
        solve(test);
}