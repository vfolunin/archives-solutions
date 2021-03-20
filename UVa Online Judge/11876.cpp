#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int divisorCount(int n) {
    int res = 0;
    for (int d = 1; d * d <= n; d++) {
        if (n % d == 0) {
            res++;
            if (d * d != n)
                res++;
        }
    }
    return res;
}

vector<int> prepare() {
    vector<int> p = { 1 };
    while (p.back() <= 1e6)
        p.push_back(p.back() + divisorCount(p.back()));
    return p;
}

void solve(int test) {
    int l, r;
    cin >> l >> r;

    static vector<int> p = prepare();

    cout << "Case " << test << ": ";
    cout << upper_bound(p.begin(), p.end(), r) - lower_bound(p.begin(), p.end(), l) << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int test = 1; test <= n; test++)
        solve(test);
}