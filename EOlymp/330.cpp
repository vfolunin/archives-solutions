#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void strip(string &s) {
    for (int i = 0; i < 2; i++) {
        while (!s.empty() && !isalnum(s.back()))
            s.pop_back();
        reverse(s.begin(), s.end());
    }
}

vector<string> split(string &line) {
    vector<string> words;
    string word;
    for (char c : line) {
        if (c != ' ') {
            word += c;
        } else {
            strip(word);
            if (!word.empty()) {
                words.push_back(word);
                word.clear();
            }
        }
    }
    strip(word);
    if (!word.empty()) {
        words.push_back(word);
        word.clear();
    }
    return words;
}

bool isPalindrome(string &s) {
    for (int l = 0, r = s.size() - 1; l < r; l++, r--)
        if (tolower(s[l]) != tolower(s[r]))
            return 0;
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    string line;
    getline(cin, line);

    vector<string> words = split(line);
    int res = -1;

    for (int i = 0; i < words.size(); i++)
        if (isPalindrome(words[i]) && (res == -1 || words[res].size() < words[i].size()))
            res = i;

    cout << res + 1;
}