#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

map<char, string> readCodes() {
    map<char, string> codes;
    while (1) {
        char c;
        cin >> c;

        if (c == '*')
            break;

        string code;
        cin >> code;

        codes[c] = code;
    }
    return codes;
}

vector<pair<string, string>> readDict(map<char, string> &codes) {
    vector<pair<string, string>> dict;
    while (1) {
        string word;
        cin >> word;

        if (word == "*")
            break;

        string code;
        for (char c : word)
            code += codes[c];

        dict.push_back({ word, code });
    }
    return dict;
}

int getDiff(string &a, string &b) {
    if (a.size() > b.size())
        return getDiff(b, a);
    return a == b.substr(0, a.size()) ? b.size() - a.size() : 1e9;
}

string findWord(string code, vector<pair<string, string>> &dict) {
    string bestWord;
    int bestDiff = 1e9, bestWordCount = 0;

    for (auto &[dictWord, dictCode] : dict) {
        int diff = getDiff(dictCode, code);
        if (bestDiff > diff) {
            bestWord = dictWord;
            bestDiff = diff;
            bestWordCount = 1;
        } else if (bestDiff == diff) {
            bestWordCount++;
        }
    }

    if (bestDiff)
        bestWord += "?";
    else if (bestWordCount > 1)
        bestWord += "!";
    return bestWord;
}

void processQueries(vector<pair<string, string>> &dict) {
    while (1) {
        string code;
        cin >> code;

        if (code == "*")
            break;

        cout << findWord(code, dict) << "\n";
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    map<char, string> codes = readCodes();
    vector<pair<string, string>> dict = readDict(codes);
    processQueries(dict);
}