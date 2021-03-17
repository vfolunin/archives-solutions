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

    string word, maxWord;

    char c;
    cin >> noskipws;
    while (cin >> c) {
        if (isalpha(c) || c == '-') {
            word += tolower(c);
        } else {
            if (word.size() > maxWord.size())
                maxWord = word;
            word.clear();
        }
    }

    cout << maxWord << "\n";
}