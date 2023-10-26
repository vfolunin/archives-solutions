#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int vowelCount(string &s) {
    static const string vowels = "aeiou";
    int res = 0;
    for (char c : s)
        res += vowels.find(c) != -1;
    return res;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int size;
    cin >> size;

    vector<string> a(size);
    for (string &s : a)
        cin >> s;

    sort(a.begin(), a.end(), [&](string &lhs, string &rhs) {
        int lhsVowels = vowelCount(lhs);
        int rhsVowels = vowelCount(rhs);
        if (lhsVowels != rhsVowels)
            return lhsVowels > rhsVowels;
        return lhs < rhs;
    });

    for (string &s : a)
        cout << s << "\n";
}