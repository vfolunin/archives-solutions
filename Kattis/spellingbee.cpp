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

    string letters;
    int wordCount;
    cin >> letters >> wordCount;

    for (int i = 0; i < wordCount; i++) {
        string word;
        cin >> word;

        bool hasOnlyLetters = 1, hasCenter = 0;
        for (char c : word) {
            int pos = letters.find(c);
            hasOnlyLetters &= pos != -1;
            hasCenter |= !pos;
        }

        if (word.size() >= 4 && hasOnlyLetters && hasCenter)
            cout << word << "\n";
    }
}
