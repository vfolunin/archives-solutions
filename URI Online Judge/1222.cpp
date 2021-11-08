#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    int wordCount, linesPerPage, charsPerLine;
    if (!(cin >> wordCount >> linesPerPage >> charsPerLine))
        return 0;

    vector<int> len(wordCount);
    for (int &l : len) {
        string word;
        cin >> word;
        l = word.size();
    }

    int lines = 0, lastChars = charsPerLine;
    for (int l : len) {
        if (lastChars + 1 + l <= charsPerLine) {
            lastChars += 1 + l;
        } else {
            lines++;
            lastChars = l;
        }
    }

    cout << (lines + linesPerPage - 1) / linesPerPage << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}