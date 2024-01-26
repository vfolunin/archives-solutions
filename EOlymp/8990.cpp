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
    getline(cin, s);

    for (char c : s) {
        cout << c;
        if (isVowel(c))
            cout << c;
    }
}