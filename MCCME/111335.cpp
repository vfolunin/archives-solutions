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

    int letterCount = 0, wordCount = 0, lineCount = 0;
    bool inWord = false;
    char c;

    cin >> noskipws;
    while (cin >> c) {
        if (isalpha(c)) {
            letterCount++;
            inWord = true;
        } else {
            if (inWord) {
                wordCount++;
                inWord = false;
            }
            if (c == '\n')
                lineCount++;
        }
    }

    cout << "Input file contains:\n";
    cout << letterCount << " letters\n";
    cout << wordCount << " words\n";
    cout << lineCount << " lines\n";
}