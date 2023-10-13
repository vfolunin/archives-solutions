#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int getValue(char c) {
    static string values = "6789TJQKA";
    return values.find(c);
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int cardCount, enemyCardCount;
    char trump;
    cin >> cardCount >> enemyCardCount >> trump;

    map<char, set<int>> cards;
    for (int i = 0; i < cardCount; i++) {
        char value, suit;
        cin >> value >> suit;

        cards[suit].insert(getValue(value));
    }

    for (int i = 0; i < enemyCardCount; i++) {
        char value, suit;
        cin >> value >> suit;

        auto it = cards[suit].upper_bound(getValue(value));
        if (it != cards[suit].end()) {
            cards[suit].erase(it);
        } else if (suit != trump && !cards[trump].empty()) {
            cards[trump].erase(cards[trump].begin());
        } else {
            cout << "NO";
            return 0;
        }
    }

    cout << "YES";
}