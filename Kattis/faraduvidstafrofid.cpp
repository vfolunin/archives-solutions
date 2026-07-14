#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool isVowel(char c) {
    string vowels = "aeiou";
    return vowels.find(tolower(c)) != -1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    string s;
    getline(cin, s);

    string vowels;
    for (char c : s)
        if (isVowel(c))
            vowels.push_back(c);

    reverse(vowels.begin(), vowels.end());

    int vi = 0;
    for (char &c : s)
        if (isVowel(c))
            c = vowels[vi++];

    cout << s;
}