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
    cin >> s;

    for (int i = 0; i + 1 < s.size(); i++) {
        if (isVowel(s[i]) == isVowel(s[i + 1])) {
            cout << "NO";
            return 0;
        }
    }

    cout << "YES";
}