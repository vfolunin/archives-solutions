#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    int width, size;
    if (!(cin >> width >> size))
        return 0;

    vector<int> a(size);
    for (int &value : a)
        cin >> value;
    a.insert(a.begin(), 0);
    a.push_back(width);

    vector<vector<long long>> res(a.size(), vector<long long>(a.size(), 1e18));
    vector<vector<int>> bestM(a.size(), vector<int>(a.size()));

    for (int l = 0, r = 1; r < a.size(); l++, r++) {
        res[l][r] = 0;
        bestM[l][r] = l;
    }

    for (int len = 3; len <= a.size(); len++) {
        for (int l = 0, r = len - 1; r < a.size(); l++, r++) {
            for (int m = bestM[l][r - 1]; m <= bestM[l + 1][r]; m++) {
                if (res[l][r] > a[r] - a[l] + res[l][m] + res[m][r]) {
                    res[l][r] = a[r] - a[l] + res[l][m] + res[m][r];
                    bestM[l][r] = m;
                }
            }
        }
    }

    cout << res[0][a.size() - 1] << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}