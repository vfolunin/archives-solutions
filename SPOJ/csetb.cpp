#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int ones(int n) {
    int res = 0;
    while (n) {
        res++;
        n &= n - 1;
    }
    return res;
}

vector<int> prepare() {
    vector<int> res(1e4 + 1);
    for (int i = 1; i < res.size(); i++)
        res[i] = res[i - 1] + ones(i);
    return res;
}

void solve() {
    int n;
    cin >> n;

    static vector<int> res = prepare();

    cout << res[n] << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;
    
    for (int i = 0; i < n; i++)
        solve();
}