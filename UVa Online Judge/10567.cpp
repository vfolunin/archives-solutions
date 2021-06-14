#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int index(char c) {
    return islower(c) ? c - 'a' : c - 'A' + 26;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    string line;
    cin >> line;

    vector<vector<int>> pos(52);
    for (int i = 0; i < line.size(); i++)
        pos[index(line[i])].push_back(i);

    int queryCount;
    cin >> queryCount;

    for (int i = 0; i < queryCount; i++) {
        cin >> line;

        int l = -1, r = -1, ok = 1;
        for (char c : line) {
            auto it = upper_bound(pos[index(c)].begin(), pos[index(c)].end(), r);
            if (it == pos[index(c)].end()) {
                ok = 0;
                break;
            }
            if (l == -1)
                l = *it;
            r = *it;
        }

        if (ok)
            cout << "Matched " << l << " " << r << "\n";
        else
            cout << "Not matched\n";
    }
}