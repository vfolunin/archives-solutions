#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool isVowel(char c) {
    string vowels = "AEIOUY";
    return vowels.find(c) != -1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    string s;
    getline(cin, s);

    int res = 0;
    for (char c : s)
        res += isVowel(c);

    cout << res;
}