#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool construct(vector<pair<int, int>> &v, int from) {
    string s;
    for (int i = from; i < v.size(); i++) {
        if (v[i].first) {
            if (v[i].first > s.size())
                return 0;
            s += s.substr(s.size() - v[i].first, v[i].second);
        } else {
            s += v[i].second;
        }
    }
    return 1;
}

bool solve() {
    vector<pair<int, int>> v;
    while (1) {
        string line;
        if (!getline(cin, line))
            return 0;

        if (line.empty())
            break;

        stringstream ss(line);

        int p;
        ss >> p;

        if (p) {
            int len;
            ss >> len;
            v.push_back({ p, len });
        } else {
            char c;
            ss >> c;
            v.push_back({ p, c });
        }
    }

    int res = 0;
    for (int i = 1; i < v.size(); i++)
        res += construct(v, i);

    cout << res << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}