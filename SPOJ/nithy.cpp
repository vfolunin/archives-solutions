#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

vector<int> prepare() {
    vector<int> res(1e4 + 1, 1e9);

    for (int i = 1; i < res.size(); i++) {
        if (i % 10 == 9) {
            res[i] = 1;
        } else {
            for (int j = 9; j <= i; j += 10)
                res[i] = min(res[i], res[i - j] + 1);
        }
    }
    
    return res;
}

void solve() {
    int n;
    cin >> n;

    static vector<int> res = prepare();

    if (res[n] != 1e9)
        cout << res[n] << "\n";
    else
        cout << "Impossible\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}