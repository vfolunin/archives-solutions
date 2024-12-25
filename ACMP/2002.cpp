#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool isVowel(char c) {
    static string vowels = "AEIOUY";
    return vowels.find(c) != -1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    string s;
    cin >> s;

    sort(s.begin(), s.end());
    int res = 0;

    do {
        res += !isVowel(s.front()) || !isVowel(s.back());
    } while (next_permutation(s.begin(), s.end()));

    cout << res;
}