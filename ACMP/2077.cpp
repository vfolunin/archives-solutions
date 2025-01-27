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
    for (int i = 0; i + 3 <= s.size(); i++)
        if (s.substr(i, 3) == "BAD" || s.substr(i, 3) == "FAT")
            pos.push_back(i);

    int res = s.size();
    for (int i = 0; i + 2 < pos.size(); i++)
        res = min(res, pos[i + 2] + 3 - pos[i]);

    cout << res;
}