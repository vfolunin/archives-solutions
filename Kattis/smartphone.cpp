#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int commonPrefixSize(const string &a, const string &b) {
    int res = 0;
    while (res < a.size() && res < b.size() && a[res] == b[res])
        res++;
    return res;
}

int pressCount(const string &a, const string &b) {
    return a.size() + b.size() - 2 * commonPrefixSize(a, b);
}

void solve() {
    string finish, start, suggest1, suggest2, suggest3;
    cin >> finish >> start >> suggest1 >> suggest2 >> suggest3;

    int res = pressCount(start, finish);

    for (const string &suggest : { suggest1, suggest2, suggest3 })
        res = min(res, 1 + pressCount(suggest, finish));
    
    cout << res << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}