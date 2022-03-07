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

    set<string> words;
    string prevWord;

    for (int i = 0; i < wordCount; i++) {
        string word;
        cin >> word;

        if (i && prevWord.back() != word.front() || words.count(word)) {
            cout << "Player " << 1 + i % 2 << " lost";
            return 0;
        }

        words.insert(word);
        prevWord = word;
    }

    cout << "Fair Game";
}