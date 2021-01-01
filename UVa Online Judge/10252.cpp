#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <string>
using namespace std;

vector<int> getLetterCount(string &s) {
    vector<int> k(26);
    for (char c : s)
        k[c - 'a']++;
    return k;
}

bool solve() {
    string a, b;
    if (!getline(cin, a))
        return 0;
    getline(cin, b);

    vector<int> ka = getLetterCount(a);
    vector<int> kb = getLetterCount(b);
    
    string res;
    for (int i = 0; i < 26; i++)
        res += string(min(ka[i], kb[i]), 'a' + i);

    cout << res << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}