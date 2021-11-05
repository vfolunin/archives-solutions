#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool isConsonant(char c) {
    static string vowels = "aeiouy";
    return vowels.find(c) == -1;
}

bool endsWith(const string &s, const string &end) {
    bool ok = 1;
    for (int i = s.size() - 1, j = end.size() - 1; ok && j >= 0; i--, j--)
        ok &= i >= 0 && s[i] == end[j];
    return ok;
}

string case1(string word) {
    if (word.size() >= 2 && isConsonant(word[word.size() - 2]) && word.back() == 'y') {
        word.pop_back();
        word += "ies";
        return word;
    }
    return "";
}

string case2(string word) {
    for (string end : {"o", "s", "ch", "sh", "x"}) {
        if (endsWith(word, end)) {
            word += "es";
            return word;
        }
    }
    return "";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int irregularWordCount, wordCount;
    cin >> irregularWordCount >> wordCount;

    map<string, string> irregularPlural;
    for (int i = 0; i < irregularWordCount; i++) {
        string singular, plural;
        cin >> singular >> plural;
        irregularPlural[singular] = plural;
    }

    for (int i = 0; i < wordCount; i++) {
        string word;
        cin >> word;

        if (irregularPlural.count(word))
            cout << irregularPlural[word] << "\n";
        else if (string plural = case1(word); !plural.empty())
            cout << plural << "\n";
        else if (string plural = case2(word); !plural.empty())
            cout << plural << "\n";
        else
            cout << word << "s\n";
    }
}