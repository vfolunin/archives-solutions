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

    vector<int> letterCount(26);
    for (char c : s)
        letterCount[c - 'a']++;

    int ruleCount;
    cin >> ruleCount;

    vector<int> pressCount(26);
    for (int i = 0; i < ruleCount; i++) {
        char c;
        cin >> c >> pressCount[c - 'a'];
        pressCount[c - 'a']--;
    }

    int res = 0;
    for (int i = 0; i < letterCount.size(); i++) {
        res += letterCount[i];
        if (pressCount[i])
            res += (letterCount[i] + pressCount[i] - 1) / pressCount[i];
    }

    cout << res;
}