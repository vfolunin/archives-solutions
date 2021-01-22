#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    int substringLength;
    string s;
    if (!(cin >> substringLength >> s))
        return 0;

    map<string, int> substringCount;
    string bestSubstring;

    for (int i = 0; i + substringLength <= s.size(); i++) {
        string substring = s.substr(i, substringLength);
        substringCount[substring]++;
        if (bestSubstring.empty() || substringCount[substring] > substringCount[bestSubstring])
            bestSubstring = substring;
    }

    cout << bestSubstring << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}