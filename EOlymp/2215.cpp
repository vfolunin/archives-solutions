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

    vector<string> words(wordCount);
    for (string &word : words)
        cin >> word;

    string text;
    cin >> text;

    vector<set<pair<int, int>>> indices(26);
    for (int i = 0; i < words.size(); i++)
        indices[words[i][0] - 'a'].insert({ i, 0 });

    vector<bool> res(words.size());
    for (char c : text) {
        set<pair<int, int>> increasingIndices = indices[c - 'a'];
        indices[c - 'a'].clear();

        for (auto &[i, j] : increasingIndices) {
            if (j + 1 < words[i].size())
                indices[words[i][j + 1] - 'a'].insert({ i, j + 1 });
            else
                res[i] = 1;
        }
    }

    for (bool res : res)
        cout << (res ? "YES\n" : "NO\n");
}