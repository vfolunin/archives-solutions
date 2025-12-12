#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <numeric>
using namespace std;

int getSum(vector<int> &p, int l, int r) {
    return p[r] - (l ? p[l - 1] : 0);
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int size, queryCount;
    cin >> size >> queryCount;

    vector<int> p(size);
    for (int &value : p)
        cin >> value;

    partial_sum(p.begin(), p.end(), p.begin());

    for (int i = 0, l = 0, r = p.size() - 1; i < queryCount; i++) {
        int m;
        cin >> m;
        m = l + m - 1;

        int lSum = getSum(p, l, m), rSum = getSum(p, m + 1, r);

        if (lSum >= rSum) {
            cout << lSum << "\n";
            l = m + 1;
        } else {
            cout << rSum << "\n";
            r = m;
        }
    }
}