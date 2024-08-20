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

    int size, queryCount;
    cin >> size >> queryCount;

    vector<int> p(size + 1);
    for (int i = 0; i < queryCount; i++) {
        int l, r;
        cin >> l >> r;

        p[l - 1]++;
        p[r]--;
    }

    partial_sum(p.begin(), p.end(), p.begin());
    sort(p.begin(), p.end());

    cin >> queryCount;

    for (int i = 0; i < queryCount; i++) {
        int limit;
        cin >> limit;

        cout << p.end() - lower_bound(p.begin(), p.end(), limit) << "\n";
    }
}