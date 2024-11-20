#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    int index;
    cin >> index;

    if (!index)
        return 0;

    string s = "1";

    for (int i = 1; i < index; i++) {
        vector<pair<int, char>> parts;
        for (char c : s) {
            if (parts.empty() || parts.back().second != c)
                parts.push_back({ 1, c });
            else
                parts.back().first++;
        }

        s = "";
        for (auto &[count, c] : parts)
            s += to_string(count) + c;
    }

    cout << s.size() << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}