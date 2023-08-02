#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool isGood(string &s) {
    vector<int> count(3);
    for (int i = 0; i < s.size(); i++) {
        if (i && s[i - 1] > s[i])
            return 0;
        count[s[i] - '0']++;
    }
    return count[0] == count[1] && count[0] == count[2];
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int queryCount;
    cin >> queryCount;

    for (int i = 0; i < queryCount; i++) {
        string s;
        cin >> s;

        cout << (isGood(s) ? "YES\n" : "NO\n");
    }
}