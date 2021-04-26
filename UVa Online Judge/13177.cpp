#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool can(vector<int> &instrument, int scoreCount, int instrumentPerScore) {
    int scoreNeed = 0;
    for (int x : instrument)
        scoreNeed += (x + instrumentPerScore - 1) / instrumentPerScore;
    return scoreNeed <= scoreCount;
}

bool solve() {
    int scoreCount, instrumentCount;
    if (!(cin >> scoreCount >> instrumentCount))
        return 0;

    vector<int> instrument(instrumentCount);
    for (int &x : instrument)
        cin >> x;

    int l = 0, r = 1e9;
    while (l + 1 < r) {
        int m = l + (r - l) / 2;
        if (can(instrument, scoreCount, m))
            r = m;
        else
            l = m;
    }

    cout << r << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}