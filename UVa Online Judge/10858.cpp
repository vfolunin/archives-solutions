#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void rec(int n, int from, vector<int> &curFactors, vector<vector<int>> &factors) {
    for (int d = from; d * d <= n; d++) {
        if (n % d == 0) {
            curFactors.push_back(d);
            rec(n / d, d, curFactors, factors);
            curFactors.pop_back();
        }
    }
    curFactors.push_back(n);
    if (curFactors.size() > 1)
        factors.push_back(curFactors);
    curFactors.pop_back();
}

bool solve() {
    int n;
    cin >> n;

    if (!n)
        return 0;

    vector<vector<int>> factors;
    vector<int> curFactors;
    rec(n, 2, curFactors, factors);

    cout << factors.size() << "\n";
    for (const vector<int> &curFactors : factors)
        for (int i = 0; i < curFactors.size(); i++)
            cout << curFactors[i] << (i + 1 < curFactors.size() ? " " : "\n");
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}