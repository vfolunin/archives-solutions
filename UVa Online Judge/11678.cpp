#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    int aCardCount, bCardCount;
    cin >> aCardCount >> bCardCount;

    if (!aCardCount && !bCardCount)
        return 0;

    set<int> aCards, bCards;
    for (int i = 0; i < aCardCount; i++) {
        int x;
        cin >> x;
        aCards.insert(x);
    }
    for (int i = 0; i < bCardCount; i++) {
        int x;
        cin >> x;
        bCards.insert(x);
    }

    set<int> aUnique, bUnique;
    for (int x : aCards)
        if (!bCards.count(x))
            aUnique.insert(x);
    for (int x : bCards)
        if (!aCards.count(x))
            bUnique.insert(x);

    cout << min(aUnique.size(), bUnique.size()) << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}