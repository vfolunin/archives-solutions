#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

vector<string> getWords(string &s) {
    vector<string> words;
    string word;
    for (char c : s) {
        if (isalpha(c)) {
            word += tolower(c);
        } else {
            if (!word.empty())
                words.push_back(word);
            word.clear();
        }
    }
    if (!word.empty())
        words.push_back(word);
    return words;
}

bool solve(int test) {
    int wordCount, lineCount;
    if (!(cin >> wordCount >> lineCount))
        return 0;

    set<string> badWords;
    for (int i = 0; i < wordCount; i++) {
        string word;
        cin >> word;
        badWords.insert(word);
    }

    cin.ignore();

    int bestBadWordCount = 0;
    vector<string> bestLines;
    for (int i = 0; i < lineCount; i++) {
        string line;
        getline(cin, line);
        vector<string> words = getWords(line);

        int badWordCount = 0;
        for (string &word : words)
            badWordCount += badWords.count(word);

        if (badWordCount > bestBadWordCount) {
            bestBadWordCount = badWordCount;
            bestLines.clear();
        }
        if (badWordCount == bestBadWordCount)
            bestLines.push_back(line);
    }

    cout << "Excuse Set #" << test << "\n";
    for (string &line : bestLines)
        cout << line << "\n";
    cout << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    for (int test = 1; solve(test); test++);
}