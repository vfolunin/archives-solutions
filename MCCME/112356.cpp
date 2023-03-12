#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

vector<string> split(string &line) {
    vector<string> words;
    string word;
    for (char c : line) {
        if (c != ' ') {
            word += c;
        } else if (!word.empty()) {
            words.push_back(word);
            word.clear();
        }
    }
    if (!word.empty())
        words.push_back(word);
    return words;
}

string join(vector<string> &words) {
    string line;
    for (int i = 0; i < words.size(); i++)
        line += words[i] + (i + 1 < words.size() ? " " : "");
    return line;
}

bool isRoman(string &s) {
    static const string ROMAN = "IVXLCDM";
    for (char c : s)
        if (ROMAN.find(c) == -1)
            return 0;
    return 1;
}

int fromRoman(string &s) {
    static const vector<pair<string, int>> CODES = {
        {"M", 1000}, {"CM", 900}, {"D", 500}, {"CD", 400},
        {"C", 100}, {"XC", 90}, {"L", 50}, {"XL", 40},
        {"X", 10}, {"IX", 9}, {"V", 5}, {"IV", 4}, {"I", 1}
    };

    int pos = 0, res = 0;
    for (auto &[code, value] : CODES) {
        while (s.substr(pos, code.size()) == code) {
            pos += code.size();
            res += value;
        }
    }
    return res;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    string line;
    getline(cin, line);

    vector<string> words = split(line);
    for (string &word : words)
        if (isRoman(word))
            word = to_string(fromRoman(word));

    cout << join(words);
}