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

    string s;
    cin >> s;

    vector<int> pos;
    for (int i = 0; i + 4 <= s.size(); i++)
        if (s.substr(i, 4) == "ACMP")
            pos.push_back(i);

    if (pos.empty()) {
        cout << s.size();
        return 0;
    }

    int res = pos[0] + 2;
    for (int i = 0; i + 1 < pos.size(); i++)
        res = max(res, pos[i + 1] - pos[i] + 2);
    res = max<int>(res, s.size() - 1 - pos.back());

    cout << res;
}