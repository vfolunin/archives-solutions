#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

vector<int> prepare() {
    vector<int> res(100, 1e9);
    res[0] = 0;

    for (int i = 0; i < res.size(); i++)
        for (int j = 0; j < i; j++)
            if ((i - j) % 10 == 7 && res[i] > res[j] + 1)
                res[i] = res[j] + 1;

    return res;
}

void solve() {
    static vector<int> res = prepare();

    int n;
    cin >> n;

    if (n < 100)
        cout << (res[n] == 1e9 ? -1 : res[n]);
    else
        cout << res[90 + n % 10];

    cout << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}