#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    string s;
    cin >> s;

    vector<string> words(1);
    for (char c : s) {
        if (isalpha(c))
            words.back() += c;
        else if (!words.back().empty())
            words.emplace_back();
    }
    if (words.back().empty())
        words.pop_back();

    sort(words.begin(), words.end());

    for (int i = 0, j = 0; i < s.size(); i++) {
        if (s[i] == '.')
            cout << s[i];
        else if (!i || s[i - 1] == '.')
            cout << words[j++];
    }
}