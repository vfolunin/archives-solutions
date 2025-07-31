#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <unordered_map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    string s;
    cin >> s;

    unordered_map<string, int> count;
    for (int l = 0; l < s.size(); l++)
        for (int r = l; r < s.size(); r++)
            count[s.substr(l, r - l + 1)]++;

    vector<pair<string, int>> res(count.begin(), count.end());
    sort(res.begin(), res.end(), [](auto &a, auto &b) {
        if (a.second != b.second)
            return a.second > b.second;
        return a.first < b.first;
    });

    for (auto &[s, count] : res)
        cout << count << " " << s << "\n";
}