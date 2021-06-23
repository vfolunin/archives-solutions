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

int getScore(string &line, set<string> &words) {
    int res = 0;
    for (const string &word : split(line))
        res += words.count(word);
    return res;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    set<string> words;
    while (1) {
        string word;
        cin >> word;

        if (word == "#")
            break;

        words.insert(word);
    }

    cin.ignore();
    string cypher;
    getline(cin, cypher);

    string res = cypher;
    int resScore = getScore(cypher, words);

    for (int i = 0; i < 26; i++) {
        for (char &c : cypher) {
            if (c == ' ')
                c = 'A';
            else if (c == 'Z')
                c = ' ';
            else
                c++;
        }
        int score = getScore(cypher, words);
        if (resScore < score) {
            resScore = score;
            res = cypher;
        }
    }

    vector<string> resWords = split(res);
    string line;
    for (string &word : resWords) {
        if (line.size() + (!line.empty()) + word.size() <= 60) {
            line += (line.empty() ? "" : " ") + word;
        } else {
            cout << line << "\n";
            line = word;
        }
    }
    cout << line << "\n";
}