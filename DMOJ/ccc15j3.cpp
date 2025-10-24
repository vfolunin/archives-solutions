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

char closestVowel(char c) {
    for (int i = 1; 1; i++) {
        if (isVowel(c - i))
            return c - i;
        if (isVowel(c + i))
            return c + i;
    }
}

char nextConsonant(char c) {
    if (c < 'z')
        c++;
    while (isVowel(c))
        c++;
    return c;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    string s;
    cin >> s;

    for (char c : s) {
        cout << c;
        if (!isVowel(c))
            cout << closestVowel(c) << nextConsonant(c);
    }
}