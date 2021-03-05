#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    vector<long long> v;
    vector<char> op;

    while (1) {
        v.emplace_back();
        cin >> v.back();

        if (cin.peek() == '\n')
            break;

        op.emplace_back();
        cin >> op.back();
    }

    vector<vector<long long>> minRes(v.size(), vector<long long>(v.size(), 1e18));
    vector<vector<long long>> maxRes(v.size(), vector<long long>(v.size(), -1e18));

    for (int i = 0; i < v.size(); i++)
        minRes[i][i] = maxRes[i][i] = v[i];

    for (int len = 2; len <= v.size(); len++) {
        for (int l = 0, r = len - 1; r < v.size(); l++, r++) {
            for (int m = l; m < r; m++) {
                long long minL = minRes[l][m], minR = minRes[m + 1][r];
                minRes[l][r] = min(minRes[l][r], op[m] == '+' ? minL + minR : minL * minR);
                long long maxL = maxRes[l][m], maxR = maxRes[m + 1][r];
                maxRes[l][r] = max(maxRes[l][r], op[m] == '+' ? maxL + maxR : maxL * maxR);
            }
        }
    }

    cout << "The maximum and minimum are ";
    cout << maxRes[0][v.size() - 1] << " and " << minRes[0][v.size() - 1] << ".\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}