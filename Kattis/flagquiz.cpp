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
        if (c != ',') {
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

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    string question;
    getline(cin, question);

    int answerCount;
    cin >> answerCount;
    cin.ignore();

    vector<string> answers(answerCount);
    vector<vector<string>> words(answerCount);
    for (int i = 0; i < answerCount; i++) {
        getline(cin, answers[i]);
        words[i] = split(answers[i]);
    }

    vector<int> maxDist(answerCount);
    for (int a = 0; a < answerCount; a++) {
        for (int b = 0; b < answerCount; b++) {
            int dist = 0;
            for (int i = 0; i < words[a].size(); i++)
                dist += words[a][i] != words[b][i];
            maxDist[a] = max(maxDist[a], dist);
        }
    }

    int resDist = *min_element(maxDist.begin(), maxDist.end());
    for (int i = 0; i < answerCount; i++)
        if (resDist == maxDist[i])
            cout << answers[i] << "\n";
}