#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    int n;
    if (!(cin >> n))
        return 0;

    vector<string> a(n);
    for (string &s : a)
        cin >> s;
    sort(a.begin(), a.end());

    int res = 0;
    for (int i = 0; i + 1 < n; i++)
        for (int j = 0; j < a[i].size() && a[i][j] == a[i + 1][j]; j++)
            res++;
    
    cout << res << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}