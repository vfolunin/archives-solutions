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

    string cards;
    cin >> cards;

    int score = 0, minCount = 1e9;
    for (char card : string("CGT")) {
        int cardCount = count(cards.begin(), cards.end(), card);
        score += cardCount * cardCount;
        minCount = min(minCount, cardCount);
    }
    score += minCount * 7;

    cout << score;
}