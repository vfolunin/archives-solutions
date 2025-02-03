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
 
    map<string, int> wordCount;
    while (1) {
        string word;
        cin >> word;

        if (word == "ENDOFINPUT")
            break;

        wordCount[word]++;
    }

    set<string> words;
    for (auto &[wordA, _] : wordCount)
        for (auto &[wordB, _] : wordCount)
            if (wordCount.count(wordA + wordB))
                words.insert(wordA + wordB);

    int res = 0;
    for (const string &word : words)
        res += wordCount[word];

    cout << res;
}