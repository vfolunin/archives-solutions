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

    string text;
    cin >> text;

    unordered_map<char, int> textCount;
    for (char c : text)
        textCount[c]++;

    string word = "inetee";

    unordered_map<char, int> wordCount;
    for (char c : word)
        wordCount[c]++;

    int res = (textCount['n'] - 1) / 2;
    for (auto &[c, count] : wordCount)
        res = min(res, textCount[c] / count);

    cout << res;
}