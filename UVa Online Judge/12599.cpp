#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    string s;
    cin >> s;

    if (s.front() != 'B' || s.back() != 'W') {
        cout << "IMPOSSIBLE\n";
        return;
    }

    int lastB = s.rfind('B');

    if (!count(s.begin(), s.begin() + lastB, 'W')) {
        cout << "1\n" << s.size();
        for (int i = 0; i < s.size(); i++)
            cout << " " << i + 1;
        cout << "\n";
    } else {
        vector<int> bPos, wPos;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == 'B')
                bPos.push_back(i);
            else
                wPos.push_back(i);
        }

        cout << "2\n" << wPos.size() << " " << bPos.front() + 1;
        for (int i = 0; i + 1 < wPos.size(); i++)
            cout << " " << wPos[i] + 1;
        cout << "\n" << bPos.size();
        for (int i = 1; i < bPos.size(); i++)
            cout << " " << bPos[i] + 1;
        cout << " " << wPos.back() + 1 << "\n";
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}