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

    vector<pair<char, int>> a;
    for (char c : s) {
        if (a.empty() || a.back().first != c)
            a.push_back({ c, 1 });
        else
            a.back().second++;
    }

    if (a.size() % 2 == 0 || a[a.size() / 2].second == 1) {
        cout << 0;
        return 0;
    }

    for (int l = a.size() / 2 - 1, r = a.size() / 2 + 1; r < a.size(); l--, r++) {
        if (a[l].first != a[r].first || a[l].second + a[r].second < 3) {
            cout << 0;
            return 0;
        }
    }

    cout << a[a.size() / 2].second + 1;
}