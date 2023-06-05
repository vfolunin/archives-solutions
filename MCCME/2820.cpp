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
        string word, dash, translation;
        cin >> word >> dash;
        while (1) {
            cin >> translation;
            if (translation.back() == ',') {
                translation.pop_back();
                dict[translation].push_back(word);
            } else {
                dict[translation].push_back(word);
                break;
            }
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