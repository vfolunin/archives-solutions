#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int ones(long long n) {
    int res = 0;
    while (n) {
        res++;
        n &= n - 1;
    }
    return res;
}

void solve() {
    int setCount;
    cin >> setCount;

    vector<long long> sets(setCount);
    for (long long &set : sets) {
        int setSize;
        cin >> setSize;

        for (int i = 0; i < setSize; i++) {
            int value;
            cin >> value;
            set |= 1LL << value;
        }
    }

    int queryCount;
    cin >> queryCount;

    for (int i = 0; i < queryCount; i++) {
        int type, a, b;
        cin >> type >> a >> b;

        if (type == 1)
            cout << ones(sets[a - 1] & sets[b - 1]) << "\n";
        else
            cout << ones(sets[a - 1] | sets[b - 1]) << "\n";
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}