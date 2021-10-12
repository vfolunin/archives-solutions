#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    int n;
    cin >> n;

    if (!n)
        return 0;

    deque<int> deck;
    for (int i = 1; i <= n; i++)
        deck.push_back(i);

    cout << "Discarded cards: ";
    while (deck.size() > 1) {
        cout << deck[0] << (deck.size() > 2 ? ", " : "\n");
        deck.pop_front();
        deck.push_back(deck[0]);
        deck.pop_front();
    }
    cout << "Remaining card: " << deck[0] << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    while (solve());
}