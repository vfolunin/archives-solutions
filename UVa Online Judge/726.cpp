#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

string read(bool untilEmpty) {
    string res, line;
    while (getline(cin, line)) {
        if (untilEmpty && line.empty())
            break;
        res += line + "\n";
    }
    return res;
}

string sortByFreq(string &s) {
    map<char, int> count;
    for (char c = 'a'; c <= 'z'; c++)
        count[c];
    for (char c : s)
        if (isalpha(c))
            count[tolower(c)]++;

    vector<pair<int, char>> pairs;
    for (auto &[c, k] : count)
        pairs.push_back({ -k, c });
    sort(pairs.begin(), pairs.end());

    string res;
    for (auto &[_, c] : pairs)
        res += c;
    return res;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    string text = read(1);
    string cypher = read(0);

    string textLetters = sortByFreq(text);
    string cypherLetters = sortByFreq(cypher);

    for (char &cypherLetter : cypher) {
        if (isalpha(cypherLetter)) {
            char textLetter = textLetters[cypherLetters.find(tolower(cypherLetter))];
            cypherLetter = isupper(cypherLetter) ? toupper(textLetter) : textLetter;
        }
    }

    cout << cypher;
}