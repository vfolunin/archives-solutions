#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool isPalindrome(string &s, int l, int r) {
    while (l < r)
        if (s[l++] != s[r--])
            return 0;
    return 1;
}

void solve() {
    string s;
    cin >> s;

    vector<int> partCount(s.size());
    for (int i = 0; i < s.size(); i++) {
        partCount[i] = 1 + (i ? partCount[i - 1] : 0);
        for (int from = i - 1; from >= 0; from--)
            if (isPalindrome(s, from, i))
                partCount[i] = min(partCount[i], 1 + (from ? partCount[from - 1] : 0));
    }

    cout << partCount.back() << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}