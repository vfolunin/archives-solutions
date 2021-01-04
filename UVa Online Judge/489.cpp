#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    int round;
    cin >> round;

    if (round == -1)
        return 0;

    cout << "Round " << round << "\n";

    string word, letters;
    cin >> word >> letters;

    set<char> guessedLetters;
    int hangmanCounter = 0;

    for (char letter : letters) {
        if (guessedLetters.count(letter))
            continue;
        guessedLetters.insert(letter);

        if (word.find(letter) != -1) {
            word.erase(remove(word.begin(), word.end(), letter), word.end());
            if (word.empty()) {
                cout << "You win.\n";
                return 1;
            }
        } else {
            hangmanCounter++;
            if (hangmanCounter == 7) {
                cout << "You lose.\n";
                return 1;
            }
        }
    }
    cout << "You chickened out.\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    while (solve());
}