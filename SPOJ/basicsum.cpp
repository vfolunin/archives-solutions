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
        int count, l;
        cin >> count >> l;
        l--;
        int r = l + count - 1;

        int lBlock = l / p.size();
        l %= p.size();
        int rBlock = r / p.size();
        r %= p.size();

        long long res = 0;
        if (lBlock < rBlock) {
            res += getSum(p, l, p.size() - 1);
            res += p.back() * (rBlock - lBlock - 1);
            res += getSum(p, 0, r);
        } else {
            res += getSum(p, l, r);
        }

        cout << res << "\n";
    }
}