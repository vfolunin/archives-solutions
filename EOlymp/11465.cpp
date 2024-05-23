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

    for (char &c : s)
        if (isVowel(c))
            c = islower(c) ? toupper(c) : tolower(c);

    cout << s;
}