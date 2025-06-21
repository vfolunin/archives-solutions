#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int rec(int n) {
    static vector<int> memo(1e4 + 1, -1);
    int &res = memo[n];
    if (res != -1)
        return res;

    res = 0;
    if (n < 2)
        return res;

    set<int> values = { rec(n - 2) };
    for (int l = 1, r = n - 2 - 1; l <= r; l++, r--)
        values.insert(rec(l) ^ rec(r));

    while (values.count(res))
        res++;
    return res;
}

void solve() {
    int n;
    cin >> n;

    cout << (rec(n) ? "Aayush\n" : "Akash\n");
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}