#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool isVowel(char c) {
    static string vowels = "aeiouy";
    return vowels.find(tolower(c)) != -1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    string s;
    cin >> s;

    int res = 0;
    for (char c : s)
        res += isVowel(c);

    cout << res;
}