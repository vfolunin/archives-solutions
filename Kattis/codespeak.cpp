#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool isVowel(char c) {
    static string vowels = "aeiou";
    return vowels.find(c) != -1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    string s;
    getline(cin, s);
    getline(cin, s);

    for (int i = 0; i < s.size(); i++) {
        if (isVowel(s[i]) && (!i || !isVowel(s[i - 1])))
            cout << "ib";
        cout << s[i];
    }
}