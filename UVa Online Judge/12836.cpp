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

void solve(int test) {
    int size;
    cin >> size;

    vector<int> a(size);
    for (int &value : a)
        cin >> value;

    vector<int> l(a.size(), 1);
    for (int i = 1; i < a.size(); i++)
        for (int j = 0; j < i; j++)
            if (a[j] < a[i])
                l[i] = max(l[i], l[j] + 1);

    vector<int> r(a.size(), 1);
    for (int i = (int)a.size() - 2; i >= 0; i--)
        for (int j = a.size() - 1; j > i; j--)
            if (a[j] < a[i])
                r[i] = max(r[i], r[j] + 1);

    vector<long long> p(a.size());
    for (int i = 0; i < p.size(); i++)
        p[i] = l[i] + r[i] - 1 + (i ? p[i - 1] : 0);

    vector<vector<long long>> res(a.size(), vector<long long>(a.size(), 1e18));
    vector<vector<int>> bestM(a.size(), vector<int>(a.size()));

    for (int i = 0; i < a.size(); i++) {
        res[i][i] = 0;
        bestM[i][i] = i;
    }

    for (int len = 2; len <= a.size(); len++) {
        for (int l = 0, r = len - 1; r < a.size(); l++, r++) {
            for (int m = bestM[l][r - 1]; m <= bestM[l + 1][r] && m < r; m++) {
                if (res[l][r] > getSum(p, l, r) + res[l][m] + res[m + 1][r]) {
                    res[l][r] = getSum(p, l, r) + res[l][m] + res[m + 1][r];
                    bestM[l][r] = m;
                }
            }
        }
    }

    cout << "Case " << test << ": " << res[0][a.size() - 1] << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int testCount;
    cin >> testCount;

    for (int test = 1; test <= testCount; test++)
        solve(test);
}