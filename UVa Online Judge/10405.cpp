#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

bool solve() {
    string a, b;
    if (!getline(cin, a))
        return 0;
    getline(cin, b);

    vector<vector<int>> lcs(a.size() + 1, vector<int>(b.size() + 1));
    for (int i = 1; i <= a.size(); i++) {
        for (int j = 1; j <= b.size(); j++) {
            if (a[i - 1] == b[j - 1])
                lcs[i][j] = lcs[i - 1][j - 1] + 1;
            else
                lcs[i][j] = max(lcs[i - 1][j], lcs[i][j - 1]);
        }
    }

    cout << lcs.back().back() << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}