#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

vector<pair<long long, long long>> digits(long long n) {
    vector<pair<long long, long long>> d;
    while (n) {
        d.emplace_back(n % 10, n % 10);
        n /= 10;
    }
    return d;
}

void solve() {
    long long n;
    cin >> n;

    vector<pair<long long, long long>> d = digits(n);
    while (1) {
        long long sum = 0;
        for (auto &[a, b] : d) {
            sum += a;
            a *= b;
        }
        if (sum == n) {
            cout << "Armstrong\n";
            return;
        }
        if (sum > n) {
            cout << "Not Armstrong\n";
            return;
        }
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}