#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <numeric>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int size, l, r, queryCount;
    cin >> size >> l >> r >> queryCount;
    l--;
    r--;

    vector<long long> p(size + 1);
    for (int i = 0; i < queryCount; i++) {
        int ql, qr;
        cin >> ql >> qr;
        ql--;
        qr--;

        p[ql]++;
        p[qr + 1]--;
    }

    partial_sum(p.begin(), p.end(), p.begin());
    partial_sum(p.begin(), p.end(), p.begin());

    cout << p[r] - (l ? p[l - 1] : 0);
}