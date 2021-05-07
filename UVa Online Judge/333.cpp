#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    string s;
    if (!getline(cin, s))
        return 0;

    for (int i = 0; i < 2; i++) {
        while (!s.empty() && s.back() == ' ')
            s.pop_back();
        reverse(s.begin(), s.end());
    }

    cout << s << " is ";

    s.erase(remove(s.begin(), s.end(), ' '), s.end());
    s.erase(remove(s.begin(), s.end(), '-'), s.end());
    if (s.size() != 10) {
        cout << "incorrect.\n";
        return 1;
    }
    for (int i = 0; i < s.size(); i++) {
        if (!isdigit(s[i]) && (i + 1 < s.size() || s[i] != 'X')) {
            cout << "incorrect.\n";
            return 1;
        }
    }

    vector<int> sums;
    for (int i = 0; i < s.size(); i++)
        sums.push_back(isdigit(s[i]) ? s[i] - '0' : 10);
    for (int i = 1; i < s.size(); i++)
        sums[i] += sums[i - 1];
    for (int i = 1; i < s.size(); i++)
        sums[i] += sums[i - 1];

    cout << (sums.back() % 11 ? "incorrect.\n" : "correct.\n");
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}