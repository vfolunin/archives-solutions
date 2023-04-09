#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

string soundex(const string &s) {
    static const string LETTERS = "bfpvcgjkqsxzdtlmnr";
    static const string NUMBERS = "111122222222334556";

    string res = s.substr(0, 1);

    for (size_t i = 1; res.size() < 4 && i < s.size(); i++) {
        size_t pos = LETTERS.find(s[i]);
        if (pos != string::npos && NUMBERS[pos] != res.back())
            res += NUMBERS[pos];
    }

    while (res.size() < 4)
        res += '0';

    return res;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    string word;
    cin >> word;

    cout << soundex(word);
}