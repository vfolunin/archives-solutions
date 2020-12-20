#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int getWordCount(const string &s) {
    int wordCount = 0;
    bool inWord = false;
    for (char c : s) {
        if (isalpha(c)) {
            if (!inWord)                
                wordCount++;
            inWord = true;
        } else {
            inWord = false;
        }
    }
    return wordCount;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    string s;
    while (getline(cin, s))
        cout << getWordCount(s) << "\n";
}