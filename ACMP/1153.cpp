#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool isVowel(char c) {
    static const string VOWELS = "aeiouy";
    return VOWELS.find(c) != -1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    string s;
    cin >> s;

    for (char &c : s)
        c = isVowel(c);

    int row = 1, res = 0;
    for (int i = 1; i < s.size(); i++) {
        if (s[i - 1] == s[i]) {
            row++;
        } else {
            res += (row - 1) / 2;
            row = 1;
        }
    }
    res += (row - 1) / 2;

    cout << res;
}