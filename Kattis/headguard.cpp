#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    string line;
    if (!(cin >> line))
        return 0;

    vector<pair<char, int>> pairs;
    for (char c : line) {
        if (pairs.empty() || pairs.back().first != c)
            pairs.push_back({ c, 1 });
        else
            pairs.back().second++;
    }

    for (auto &[c, count] : pairs)
        cout << count << c;
    cout << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}