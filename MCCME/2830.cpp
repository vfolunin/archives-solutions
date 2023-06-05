#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int wordCount;
    cin >> wordCount;

    map<string, vector<string>> dict;
    for (int i = 0; i < wordCount; i++) {
        string word;
        int translationCount;
        cin >> word >> translationCount;

        for (int j = 0; j < translationCount; j++) {
            string translation;
            cin >> translation;
            dict[translation].push_back(word);
        }
    }

    cout << dict.size() << "\n";
    for (auto &[translation, words] : dict) {
        cout << translation << " - ";
        sort(words.begin(), words.end());
        for (int i = 0; i < words.size(); i++)
            cout << words[i] << (i + 1 < words.size() ? ", " : "\n");
    }
}