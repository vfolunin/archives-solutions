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

    string word, guess;
    cin >> word >> guess;

    set<char> letters(word.begin(), word.end());
    int wrong = 0;

    for (char letter : guess) {
        if (letters.count(letter)) {
            letters.erase(letter);
            if (letters.empty()) {
                cout << "WIN";
                return 0;
            }
        } else {
            wrong++;
            if (wrong == 10) {
                cout << "LOSE";
                return 0;
            }
        }
    }
}