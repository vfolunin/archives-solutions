#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

string rec(vector<vector<int>> &pos, int from) {
    for (int digit = pos.size() - 1; digit >= 0; digit--) {
        if (pos[digit].empty())
            continue;

        auto it = lower_bound(pos[digit].begin(), pos[digit].end(), from);
        if (it == pos[digit].end())
            continue;

        int canTake = 0, needTake = 0;
        for (vector<int> &p : pos) {
            canTake += !p.empty() && *it <= p.back();
            needTake += !p.empty();
        }

        if (canTake < needTake)
            continue;

        pos[digit].clear();
        return string(1, digit + '0') + rec(pos, *it);
    }
    return "";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    string s;
    cin >> s;

    vector<vector<int>> pos(10);
    for (int i = 0; i < s.size(); i++)
        pos[s[i] - '0'].push_back(i);

    cout << rec(pos, 0);
}