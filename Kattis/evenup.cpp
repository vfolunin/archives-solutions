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

    int cardCount;
    cin >> cardCount;

    vector<int> cards;
    for (int i = 0; i < cardCount; i++) {
        cin >> cards.emplace_back();
        if (cards.size() >= 2 && (cards[cards.size() - 2] + cards[cards.size() - 1]) % 2 == 0) {
            cards.pop_back();
            cards.pop_back();
        }
    }

    cout << cards.size();
}