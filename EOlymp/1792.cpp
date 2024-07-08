#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <unordered_map>
#include <string>
using namespace std;

bool solve() {
    int substringLength;
    string s;
    if (!(cin >> substringLength >> s))
        return 0;

    unordered_map<string, int> substringCount;
    string bestSubstring;

    for (int i = 0; i + substringLength <= s.size(); i++) {
        string substring = s.substr(i, substringLength);
        substringCount[substring]++;
        if (bestSubstring.empty() || substringCount[bestSubstring] < substringCount[substring] ||
            substringCount[bestSubstring] == substringCount[substring] && bestSubstring > substring)
            bestSubstring = substring;
    }

    cout << bestSubstring << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    while (solve());
}