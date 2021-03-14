#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

vector<vector<long long>> prepare() {
    vector<vector<long long>> seq = { { 0, 1 }, { 0, 1 } };
    while (seq[0].back() <= 1e9) {
        long long k0 = seq[0].back() + seq[1].back();
        long long k1 = seq[0].back();
        seq[0].push_back(k0);
        seq[1].push_back(k1);
    }
    return seq;
}

void solve() {
    long long n;
    cin >> n;
    n--;

    static vector<vector<long long>> seq = prepare();

    int len = 1;
    while (n >= seq[1][len]) {
        n -= seq[1][len];
        len++;
    }

    cout << 1;
    for (int tail = len - 1; tail > 0; tail--) {
        if (n < seq[0][tail]) {
            cout << 0;
        } else {
            n -= seq[0][tail];
            cout << 1;
        }
    }
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