#include <iostream>
#include <sstream>
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
    stringstream ss(line);
    string word;
    while (ss >> word)
        words.push_back(word);

    return words;
}

void solve() {
    int wordCount, lineCount;
    cin >> wordCount >> lineCount;

    map<string, vector<string>> dict;
    for (int i = 0; i < wordCount; i++) {
        string word;
        cin >> word;
        cin.ignore();
        dict[word] = readWords();
    }

    for (int i = 0; i < lineCount; i++) {
        vector<string> words = readWords(), translation;
        for (string &word : words) {
            if (dict.count(word))
                translation.insert(translation.end(), dict[word].begin(), dict[word].end());
            else
                translation.push_back(word);
        }

        for (int j = 0; j < translation.size(); j++)
            cout << translation[j] << (j + 1 < translation.size() ? " " : "\n");
    }
    cout << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}