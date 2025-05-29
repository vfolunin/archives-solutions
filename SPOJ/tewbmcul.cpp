#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

long long getSum(vector<long long> &p, int l, int r) {
    return p[r] - (l ? p[l - 1] : 0);
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int size, queryCount;
    cin >> size >> queryCount;

    vector<long long> p(size);
    for (int i = 0; i < size; i++) {
        cin >> p[i];
        if (i)
            p[i] += p[i - 1];
    }

    for (int i = 0; i < queryCount; i++) {
        int l, r;
        cin >> l >> r;

        cout << getSum(p, l - 1, r - 1) << "\n";
    }
}