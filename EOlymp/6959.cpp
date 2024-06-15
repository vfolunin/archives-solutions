#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <numeric>
using namespace std;

long long getSum(vector<long long> &p, int l, int r) {
    return p[r] - (l ? p[l - 1] : 0);
}

void solve() {
    int size, queryCount;
    cin >> size >> queryCount;

    vector<long long> p(size);
    for (long long &value : p)
        cin >> value;
    partial_sum(p.begin(), p.end(), p.begin());

    for (int i = 0; i < queryCount; i++) {
        int l, r;
        cin >> l >> r;

        cout << getSum(p, l, r) << "\n";
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