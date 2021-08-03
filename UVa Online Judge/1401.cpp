#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <unordered_set>
#include <map>
#include <string>
using namespace std;

const long long MOD = 20071027;

bool solve(int test) {
    string text;
    int wordCount;
    if (!(cin >> text >> wordCount))
        return 0;

    unordered_set<string> words;
    int maxWordSize = 0;
    for (int i = 0; i < wordCount; i++) {
        string word;
        cin >> word;
        maxWordSize = max<int>(maxWordSize, word.size());
        reverse(word.begin(), word.end());
        words.insert(word);
    }

    vector<long long> ways(text.size() + 1);
    ways[0] = 1;
    for (int i = 1; i <= text.size(); i++) {
        string word;
        for (int j = 1; j <= maxWordSize && j <= i; j++) {
            word += text[i - j];
            if (words.count(word))
                ways[i] = (ways[i] + ways[i - j]) % MOD;
        }
    }

    cout << "Case " << test << ": " << ways.back() << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    for (int test = 1; solve(test); test++);
}