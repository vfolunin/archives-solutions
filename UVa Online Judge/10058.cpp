#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

vector<string> readWords(string &line) {
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

bool checkVerb(vector<string> &words, int &pos) {
    static set<string> verbs = { "hate", "love", "know", "like", "hates", "loves", "knows", "likes" };
    if (pos == words.size() || !verbs.count(words[pos]))
        return 0;
    pos++;
    return 1;
}

bool checkActor(vector<string> &words, int &pos) {
    static set<string> articles = { "a", "the" };
    if (pos < words.size() && articles.count(words[pos]))
        pos++;
    static set<string> nouns = { "tom", "jerry", "goofy", "mickey", "jimmy", "dog", "cat", "mouse" };
    if (pos == words.size() || !nouns.count(words[pos]))
        return 0;
    pos++;
    return 1;
}

bool checkActiveList(vector<string> &words, int &pos) {
    while (1) {
        if (pos == words.size() || !checkActor(words, pos))
            return 0;
        if (pos == words.size() || words[pos] != "and")
            break;
        pos++;
    }
    return 1;
}

bool checkAction(vector<string> &words, int &pos) {
    if (pos == words.size() || !checkActiveList(words, pos))
        return 0;
    if (pos == words.size() || !checkVerb(words, pos))
        return 0;
    if (pos == words.size() || !checkActiveList(words, pos))
        return 0;
    return 1;
}

bool checkStatement(vector<string> &words, int &pos) {
    if (!checkAction(words, pos))
        return 0;
    while (pos < words.size()) {
        if (words[pos] != ",")
            return 0;
        pos++;
        if (pos == words.size() || !checkAction(words, pos))
            return 0;
    }
    return 1;
}

bool solve() {
    string line;
    if (!getline(cin, line))
        return 0;

    vector<string> words = readWords(line);
    int pos = 0;

    if (checkStatement(words, pos))
        cout << "YES I WILL\n";
    else
        cout << "NO I WON'T\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}