#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

vector<long long> getF() {
    vector<long long> f = { 1 };
    while (f.size() <= 12)
        f.push_back(f.back() * f.size());
    return f;
}

void solve() {
    int n;
    cin >> n;

    static vector<long long> f = getF();

    long long num = 0;
    for (int i = 0; i <= n; i++)
        num += f[n] / f[i] * (i % 2 ? -1 : 1);

    cout << num << "/" << f[n] << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}