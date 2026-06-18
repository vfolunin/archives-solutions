#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <numeric>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int cardCount;
    cin >> cardCount;

    vector<int> cards(cardCount);
    for (int &card : cards)
        cin >> card;

    vector<int> order(cards.size());
    iota(order.begin(), order.end(), 0);
    sort(order.begin(), order.end(), [&](int l, int r) {
        return cards[l] < cards[r];
    });

    for (int l = 0, r = order.size() - 1; l < r; l++, r--)
        cout << order[l] + 1 << " " << order[r] + 1 << "\n";
}