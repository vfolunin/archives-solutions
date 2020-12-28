#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

bool solve() {
    string s;
    cin >> s;
    if (s == "#")
        return 0;

    vector<int> maxK(26);
    for (char c : s)
        maxK[c - 'a']++;

    vector<int> curK = maxK;
    for (int i = s.size() - 1; i >= 0; i--) {
        curK[s[i] - 'a']--;

        for (int j = s[i] - 'a' + 1; j < 26; j++) {
            if (curK[j] == maxK[j])
                continue;

            s[i] = 'a' + j;
            curK[j]++;

            cout << s.substr(0, i + 1);
            for (int c = 0; c < 26; c++)
                cout << string(maxK[c] - curK[c], 'a' + c);
            cout << "\n";

            return 1;
        }
    }

    cout << "No Successor\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}