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

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int size;
    cin >> size;

    vector<long long> p(size);
    for (long long &value : p)
        cin >> value;

    partial_sum(p.begin(), p.end(), p.begin());

    int queryCount;
    cin >> queryCount;

    for (int i = 0; i < queryCount; i++) {
        int l, r;
        cin >> l >> r;

        cout << getSum(p, l, r) << "\n";
    }
}