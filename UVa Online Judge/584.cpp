#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

vector<string> readTokens() {
    string line;
    getline(cin, line);
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

bool solve() {
    vector<string> tokens = readTokens();

    if (tokens[0] == "Game")
        return 0;

    vector<int> rollScore(tokens.size());
    for (int i = 0; i < tokens.size(); i++) {
        if (tokens[i] == "X")
            rollScore[i] = 10;
        else if (tokens[i] == "/")
            rollScore[i] = 10 - rollScore[i - 1];
        else
            rollScore[i] = stoi(tokens[i]);
    }

    vector<int> frameScore(tokens.size());
    for (int f = 0, i = 0; f < 10; f++) {
        if (rollScore[i] == 10) {
            frameScore[f] = rollScore[i] + rollScore[i + 1] + rollScore[i + 2];
            i++;
        } else if (rollScore[i] + rollScore[i + 1] == 10) {
            frameScore[f] = rollScore[i] + rollScore[i + 1] + rollScore[i + 2];
            i += 2;
        } else {
            frameScore[f] = rollScore[i] + rollScore[i + 1];
            i += 2;
        }
    }

    int res = 0;
    for (int score : frameScore)
        res += score;

    cout << res << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}