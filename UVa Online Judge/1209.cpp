#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int dist(const string &s) {
    int res = 1e9;
    for (int i = 1; i < s.size(); i++)
        res = min(res, abs(s[i - 1] - s[i]));
    return res;
}

bool solve() {
    string s;
    if (!(cin >> s))
        return 0;

    for (int i = 0; i < 10; i++)
        prev_permutation(s.begin(), s.end());
    
    string bestS = s;
    int bestDist = dist(s);

    for (int i = 0; i < 20; i++) {
        next_permutation(s.begin(), s.end());
        int curDist = dist(s);
        if (curDist > bestDist || curDist == bestDist && s < bestS) {
            bestS = s;
            bestDist = curDist;
        }
    }

    cout << bestS << bestDist << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}