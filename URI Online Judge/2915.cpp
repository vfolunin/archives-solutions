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

    vector<int> cards(cardCount);
    for (int &card : cards)
        cin >> card;

    int pileCount = 1;
    for (int i = 1; i < cardCount; i++)
        pileCount += cards[i - 1] < cards[i];

    cout << pileCount << "\n";
}