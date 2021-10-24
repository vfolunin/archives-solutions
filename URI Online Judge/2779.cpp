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

    int slotCount, cardCount;
    cin >> slotCount >> cardCount;

    set<int> cards;
    for (int i = 0; i < cardCount; i++) {
        int card;
        cin >> card;
        cards.insert(card);
    }

    cout << slotCount - cards.size() << "\n";
}