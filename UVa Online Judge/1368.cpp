#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    int stringCount, stringLen;
    cin >> stringCount >> stringLen;

    vector<string> strings(stringCount);
    for (string &s : strings)
        cin >> s;

    string consensusString;
    int hammingDistance = 0;

    for (int i = 0; i < stringLen; i++) {
        map<char, int> count;
        int bestLetter = 'A';

        for (string &s : strings) {
            count[s[i]]++;
            if (count[s[i]] > count[bestLetter] || count[s[i]] == count[bestLetter] && s[i] < bestLetter)
                bestLetter = s[i];
        }

        consensusString += bestLetter;
        hammingDistance += stringCount - count[bestLetter];
    }

    cout << consensusString << "\n" << hammingDistance << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}