#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve(int test) {
    int limit;
    if (!(cin >> limit))
        return 0;

    string line;
    cin.ignore();
    getline(cin, line);

    string s;
    vector<int> pos;

    for (int i = 0; i < line.size(); i++) {
        if (isalpha(line[i])) {
            s += tolower(line[i]);
            pos.push_back(i);
        }
    }

    vector<vector<int>> errorCount(s.size(), vector<int>(s.size()));
    int maxLen = 1, maxStart = 0;

    for (int len = 2; len <= s.size(); len++) {
        for (int l = 0, r = len - 1; r < s.size(); l++, r++) {
            errorCount[l][r] = errorCount[l + 1][r - 1] + (s[l] != s[r]);
            if (errorCount[l][r] <= limit && maxLen < pos[r] - pos[l] + 1) {
                maxLen = pos[r] - pos[l] + 1;
                maxStart = pos[l];
            }
        }
    }

    cout << "Case " << test << ": " << maxLen << " " << maxStart + 1 << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    for (int test = 1; solve(test); test++);
}