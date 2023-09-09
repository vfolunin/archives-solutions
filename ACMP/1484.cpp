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

    string minWord, maxWord;
    for (string word; cin >> word; ) {
        if (minWord == "" || minWord.size() > word.size() || minWord.size() == word.size() && minWord < word)
            minWord = word;
        if (maxWord == "" || maxWord.size() < word.size() || maxWord.size() == word.size() && maxWord > word)
            maxWord = word;
    }

    cout << minWord << "\n" << maxWord;
}