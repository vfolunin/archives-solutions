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

    int size;
    cin >> size;

    vector<vector<string>> words(26);
    for (int i = 0; i < size; i++) {
        string word;
        cin >> word;

        words[word[0] - 'a'].push_back(word);
    }

    for (vector<string> &words : words) {
        if (!words.empty()) {
            sort(words.begin(), words.end());
            for (int i = 0; i < words.size(); i++)
                cout << words[i] << (i + 1 < words.size() ? ", " : "\n");
        }
    }
}