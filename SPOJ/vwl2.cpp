#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool isVowel(char c) {
    string vowels = "aeiou";
    return vowels.find(c) != -1;
}

void solve() {
    string s;
    cin >> s;

    int vowelCount = 0;
    for (char c : s)
        vowelCount += isVowel(c);

    cout << s << "\n" << (vowelCount * 2 > s.size()) << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}