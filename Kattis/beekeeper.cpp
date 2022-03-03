#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    int wordCount;
    cin >> wordCount;

    if (!wordCount)
        return 0;

    int bestPairCount = -1;
    string bestWord;

    for (int i = 0; i < wordCount; i++) {
        string word;
        cin >> word;

        int pairCount = 0;
        for (int j = 1; j < word.size(); j++) {
            static const string vowels = "aeiouy";
            pairCount += word[j - 1] == word[j] && vowels.find(word[j]) != -1;
        }

        if (bestPairCount < pairCount) {
            bestPairCount = pairCount;
            bestWord = word;
        }
    }

    cout << bestWord << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}