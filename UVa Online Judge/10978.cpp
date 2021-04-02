#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    int cardCount;
    cin >> cardCount;

    if (!cardCount)
        return 0;

    vector<string> cards(cardCount);
    int pos = cardCount - 1;

    for (int i = 0; i < cardCount; i++) {
        string card, name;
        cin >> card >> name;

        for (char c : name) {
            do {
                pos = (pos + 1) % cardCount;
            } while (!cards[pos].empty());
        }

        cards[pos] = card;
    }
    
    for (int i = 0; i < cardCount; i++)
        cout << cards[i] << (i + 1 < cardCount ? " " : "\n");
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}