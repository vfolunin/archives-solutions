#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int commonSuffixLen(string &a, int ar, string &b, int br) {
    int res = 0;
    while (ar >= 0 && br >= 0 && a[ar] == b[br]) {
        res++;
        ar--;
        br--;
    }
    return res;
}

bool solve() {
    int k;
    string a, b;
    if (!(cin >> k >> a >> b))
        return 0;

    vector<vector<int>> lcs(a.size() + 1, vector<int>(b.size() + 1));
    for (int ai = 1; ai <= a.size(); ai++) {
        for (int bi = 1; bi <= b.size(); bi++) {
            if (int csl = commonSuffixLen(a, ai - 1, b, bi - 1); csl >= k)
                for (int i = k; i <= csl; i++)
                    lcs[ai][bi] = max(lcs[ai][bi], lcs[ai - i][bi - i] + i);
            lcs[ai][bi] = max(lcs[ai][bi], max(lcs[ai - 1][bi], lcs[ai][bi - 1]));
        }
    }

    cout << lcs[a.size()][b.size()] << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}