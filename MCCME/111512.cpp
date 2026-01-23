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

    vector<vector<string>> words(26);
    for (int i = 0; i < wordCount; i++) {
        string word;
        cin >> word;

        words[word[0] - 'a'].push_back(word);
    }

    int resI = 0;
    for (int i = 1; i < words.size(); i++)
        if (words[resI].size() <= words[i].size())
            resI = i;

    cout << words[resI].back();
}