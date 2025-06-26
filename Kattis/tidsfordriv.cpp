#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <unordered_map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int cardCount;
    cin >> cardCount;

    unordered_map<string, int> count;
    for (string card : { "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A" })
        count[card] = 4;

    for (int i = 0; i < cardCount; i++) {
        string card;
        cin >> card;

        count[card.substr(0, card.size() - 1)]--;
    }

    int maxCount = 0;
    for (auto &[_, count] : count)
        maxCount = max(maxCount, count);

    cout << fixed << maxCount / (52.0 - cardCount);
}