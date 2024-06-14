#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool matches(string &pattern, string &word) {
    for (int i = 0; i < pattern.size(); i++)
        if (pattern[i] != '*' && pattern[i] != word[i])
            return 0;
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    string pattern;
    int wordCount;
    cin >> pattern >> wordCount;

    vector<string> res;
    for (int i = 0; i < wordCount; i++) {
        string word;
        cin >> word;

        if (matches(pattern, word))
            res.push_back(word);
    }

    cout << res.size() << "\n";
    for (string &word : res)
        cout << word << "\n";
}