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

    int wordCount, queryCount;
    cin >> wordCount >> queryCount;

    vector<set<pair<int, string>>> words(26);
    for (int i = 0; i < wordCount; i++) {
        string word;
        cin >> word;

        words[word[0] - 'a'].insert({ 0, word });
    }

    for (int i = 0; i < queryCount; i++) {
        char c;
        cin >> c;

        auto [count, word] = *words[c - 'a'].begin();
        words[c - 'a'].erase(words[c - 'a'].begin());
        words[c - 'a'].insert({ count + 1, word });

        cout << word << "\n";
    }
}