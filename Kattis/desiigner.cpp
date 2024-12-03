#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool isVowel(char c) {
    static const string vowels = "aeiouy";
    return vowels.find(c) != -1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    string s;
    cin >> s;

    bool ok = s[0] == 'b' && s.size() > 3;
    for (int i = 1; ok && i + 1 < s.size(); i++)
        ok &= s[i] == 'r';
    ok &= isVowel(s.back());

    cout << (ok ? "Jebb" : "Neibb");
}