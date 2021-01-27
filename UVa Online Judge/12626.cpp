#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    string letters;
    cin >> letters;

    map<char, int> letterCount;
    for (char letter : letters)
        letterCount[letter]++;

    int res = 1e9;
    res = min(res, letterCount['M']);
    res = min(res, letterCount['A'] / 3);
    res = min(res, letterCount['R'] / 2);
    res = min(res, letterCount['G']);
    res = min(res, letterCount['I']);
    res = min(res, letterCount['T']);
    cout << res << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}