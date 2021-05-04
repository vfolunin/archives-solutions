#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

vector<unsigned long long> prepare() {
    vector<unsigned long long> res = { 0, 0, 1, 3 };
    for (int i = 3; i <= 65; i++)
        res.push_back(res[i - 2] + 3 * (1ULL << (i - 2)));
    return res;
}

void solve() {
    int n;
    cin >> n;

    static vector<unsigned long long> res = prepare();

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