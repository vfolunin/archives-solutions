#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    string a, b;
    if (!(cin >> a >> b))
        return 0;

    vector<int> countA(26);
    for (char c : a)
        countA[c - 'a']++;

    vector<int> countB(26);
    for (char c : b)
        countB[c - 'a']++;

    for (int i = 0; i < 26; i++)
        for (int j = 0; j < min(countA[i], countB[i]); j++)
            cout << (char)(i + 'a');

    cout << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}