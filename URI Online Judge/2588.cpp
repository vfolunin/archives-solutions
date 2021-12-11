#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    string s;
    if (!(cin >> s))
        return 0;

    map<char, int> count;
    for (char c : s)
        count[c]++;

    int odd = 0;
    for (auto &[c, k] : count)
        odd += k % 2;

    cout << max(0, odd - 1) << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}