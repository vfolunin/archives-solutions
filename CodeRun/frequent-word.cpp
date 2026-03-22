#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <unordered_map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    unordered_map<string, int> count;
    string word, bestWord;

    while (cin >> word) {
        count[word]++;
        if (bestWord.empty() || count[bestWord] < count[word] ||
            count[bestWord] == count[word] && bestWord > word)
            bestWord = word;
    }

    cout << bestWord;
}