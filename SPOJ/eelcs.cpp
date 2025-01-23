#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    string a, b;
    cin >> a >> b;

    vector<vector<int>> lcs(a.size() + 1, vector<int>(b.size() + 1));
    for (int ai = 1; ai <= a.size(); ai++) {
        for (int bi = 1; bi <= b.size(); bi++) {
            if (a[ai - 1] == b[bi - 1])
                lcs[ai][bi] = lcs[ai - 1][bi - 1] + 1;
            else
                lcs[ai][bi] = max(lcs[ai - 1][bi], lcs[ai][bi - 1]);
        }
    }

    cout << lcs[a.size()][b.size()];
}