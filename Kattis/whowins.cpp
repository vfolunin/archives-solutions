#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int getScore() {
    int cardCount;
    cin >> cardCount;

    int score = 0, aceCount = 0;
    for (int i = 0; i < cardCount; i++) {
        string card;
        cin >> card;

        if (isdigit(card[0]))
            score += stoi(card);
        else if (card == "A")
            aceCount++;
        else
            score += 10;
    }

    int resScore = score + aceCount;
    for (int a1 = 0, a11 = aceCount; a1 <= aceCount; a1++, a11--)
        if (score + a1 + a11 * 11 <= 21)
            resScore = max(resScore, score + a1 + a11 * 11);

    return resScore;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int dealerScore = getScore();
    int playerScore = getScore();

    if (dealerScore > 21 && playerScore > 21 || dealerScore == playerScore)
        cout << "Push";
    else if (dealerScore > 21 || playerScore <= 21 && playerScore > dealerScore)
        cout << "Player";
    else
        cout << "Dealer";
}