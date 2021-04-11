#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

vector<int> getP() {
    vector<int> p(300);
    p[1] = p[2] = 1;
    for (int i = 3; i < p.size(); i++)
        p[i] = (p[i - 1] + p[i - 2]) % 100;
    for (int i = 1; i < p.size(); i++)
        p[i] += p[i - 1];
    return p;
}

long long sum(long long r) {
    static vector<int> p = getP();
    return r / 300 * p.back() + p[r % 300];
}

void solve() {
    long long l, r;
    cin >> l >> r;

    cout << sum(r) - sum(l - 1) << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}