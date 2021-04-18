#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

vector<string> readWords() {
    string line;
    getline(cin, line);

    vector<string> words;
    string word;

    for (char c : line) {
        if (isalnum(c)) {
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

bool solve() {
    vector<string> words = readWords();
    if (words.empty())
        return 0;

    static map<string, int> val = {
        { "zero", 0 }, { "one", 1 }, { "two", 2 }, { "three", 3 }, { "four", 4 },
        { "five", 5 }, { "six", 6 }, { "seven", 7 }, { "eight", 8 }, { "nine", 9 },
        { "ten", 10 }, { "eleven", 11 }, { "twelve", 12 }, { "thirteen", 13 }, { "fourteen", 14 },
        { "fifteen", 15 }, { "sixteen", 16 }, { "seventeen", 17 }, { "eighteen", 18 }, { "nineteen", 19 },
        { "twenty", 20 }, { "thirty", 30 }, { "forty", 40 }, { "fifty", 50 }, { "sixty", 60 },
        { "seventy", 70 }, { "eighty", 80 }, { "ninety", 90 }
    };

    static map<string, int> mul = {
        { "thousand", 1000 }, { "million", 1000000 }
    };

    int sign = 1;
    if (words[0] == "negative")
        sign = -1;

    vector<int> parts = { 0 };

    for (string &word : words) {
        if (word == "hundred") {
            parts.back() *= 100;
        } else if (val.count(word)) {
            parts.back() += val[word];
        } else if (mul.count(word)) {
            parts.back() *= mul[word];
            parts.push_back(0);
        }
    }

    int sum = 0;
    for (int part : parts)
        sum += part;
    sum *= sign;

    cout << sum << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}