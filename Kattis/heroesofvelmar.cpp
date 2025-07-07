#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <unordered_map>
#include <string>
using namespace std;

unordered_map<string, int> prepareCardPoints() {
    unordered_map<string, int> cardPoints;

    cardPoints["Anvil"] = 7;
    cardPoints["Frostwhisper"] = 2;
    cardPoints["Gale"] = 5;
    cardPoints["Guardian"] = 8;
    cardPoints["Ironwood"] = 3;
    cardPoints["Ranger"] = 4;
    cardPoints["Seraphina"] = 1;
    cardPoints["Shadow"] = 6;
    cardPoints["Thunderheart"] = 6;
    cardPoints["Vexia"] = 3;
    cardPoints["Voidclaw"] = 3;
    cardPoints["Zenith"] = 4;

    return cardPoints;
}

int getRoundPoints(int round) {
    int cardCount;
    cin >> cardCount;
    
    int res = 0, sCount = 0;
    for (int i = 0; i < cardCount; i++) {
        string card;
        cin >> card;

        static unordered_map<string, int> cardPoints = prepareCardPoints();
        res += cardPoints[card];

        sCount += card == "Seraphina";
        if (card == "Thunderheart" && cardCount == 4)
            res += 6;
        if (card == "Zenith" && round == 1)
            res += 5;
    }

    return res + sCount * (cardCount - 1);
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int aWins = 0, bWins = 0, aSum = 0, bSum = 0;
    for (int round = 0; round < 3; round++) {
        int aPoints = getRoundPoints(round);
        int bPoints = getRoundPoints(round);

        aWins += aPoints > bPoints;
        bWins += bPoints > aPoints;

        aSum += aPoints;
        bSum += bPoints;
    }

    if (aWins == bWins && aSum == bSum)
        cout << "Tie";
    else if (aWins > bWins || aWins == bWins && aSum > bSum)
        cout << "Player 1";
    else
        cout << "Player 2";
}