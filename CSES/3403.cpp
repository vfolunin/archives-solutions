#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

vector<int> getLcs(vector<int> &a, vector<int> &b) {
    vector<vector<int>> lcsSize(a.size() + 1, vector<int>(b.size() + 1));
    vector<vector<pair<int, int>>> from(a.size() + 1, vector<pair<int, int>>(b.size() + 1));

    for (int ai = 1; ai <= a.size(); ai++) {
        for (int bi = 1; bi <= b.size(); bi++) {
            if (a[ai - 1] == b[bi - 1]) {
                lcsSize[ai][bi] = lcsSize[ai - 1][bi - 1] + 1;
                from[ai][bi] = { ai - 1, bi - 1 };
            } else if (lcsSize[ai - 1][bi] > lcsSize[ai][bi - 1]) {
                lcsSize[ai][bi] = lcsSize[ai - 1][bi];
                from[ai][bi] = { ai - 1, bi };
            } else {
                lcsSize[ai][bi] = lcsSize[ai][bi - 1];
                from[ai][bi] = { ai, bi - 1 };
            }
        }
    }

    vector<int> lcs;
    for (int ai = a.size(), bi = b.size(); ai || bi; ) {
        auto [pai, pbi] = from[ai][bi];
        if (pai != ai && pbi != bi)
            lcs.push_back(a[ai - 1]);
        ai = pai;
        bi = pbi;
    }
    reverse(lcs.begin(), lcs.end());

    return lcs;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int aSize, bSize;
    cin >> aSize >> bSize;

    vector<int> a(aSize);
    for (int &value : a)
        cin >> value;

    vector<int> b(bSize);
    for (int &value : b)
        cin >> value;
    
    vector<int> lcs = getLcs(a, b);

    cout << lcs.size() << "\n";
    for (int value : lcs)
        cout << value << " ";
}