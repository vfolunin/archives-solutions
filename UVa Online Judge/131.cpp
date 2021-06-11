#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool straight(vector<int> &vals);
bool flush(vector<char> &suits);
bool straightFlush(vector<int> &vals, vector<char> &suits) {
    return straight(vals) && flush(suits);
}

bool four(vector<int> &vals) {
    return vals[0] == vals[3] || vals[1] == vals[4];
}

bool fullHouse(vector<int> &vals) {
    return vals[0] == vals[1] && vals[2] == vals[4] || vals[0] == vals[2] && vals[3] == vals[4];
}

bool flush(vector<char> &suits) {
    return suits[0] == suits[4];
}

bool straight(vector<int> &vals) {
    for (int i = 1; i < 5; i++)
        if (vals[0] + i != vals[i])
            return (i == 4 && vals[0] == 0 && vals[4] == 12);
    return 1;
}

bool three(vector<int> &vals) {
    return vals[0] == vals[2] || vals[1] == vals[3] || vals[2] == vals[4];
}

bool twoPairs(vector<int> &vals) {
    return vals[0] == vals[1] && (vals[2] == vals[3] || vals[3] == vals[4]) || vals[1] == vals[2] && vals[3] == vals[4];
}


bool onePair(vector<int> &vals) {
    for (int i = 1; i < 5; i++)
        if (vals[i - 1] == vals[i])
            return 1;
    return 0;
}

int value(string &card) {
    static string values = "23456789TJQKA";
    return values.find(card[0]);
}

int hand(vector<string> &cards) {
    vector<int> vals(5);
    vector<char> suits(5);
    for (int i = 0; i < 5; i++) {
        vals[i] = value(cards[i]);
        suits[i] = cards[i][1];
    }
    sort(vals.begin(), vals.end());
    sort(suits.begin(), suits.end());

    if (straightFlush(vals, suits))
        return 0;
    if (four(vals))
        return 1;
    if (fullHouse(vals))
        return 2;
    if (flush(suits))
        return 3;
    if (straight(vals))
        return 4;
    if (three(vals))
        return 5;
    if (twoPairs(vals))
        return 6;
    if (onePair(vals))
        return 7;
    return 8;
}

bool solve() {
    vector<string> cards(10);
    for (string &card : cards)
        if (!(cin >> card))
            return 0;

    int res = 8;
    for (int mask = 0; mask < 32; mask++) {
        vector<string> selectedCards;
        for (int i = 0; i < 5; i++)
            if (mask & (1 << i))
                selectedCards.push_back(cards[i]);
        for (int i = 5; selectedCards.size() < 5; i++)
            selectedCards.push_back(cards[i]);
        res = min(res, hand(selectedCards));
    }

    static vector<string> hands = {
        "straight-flush", "four-of-a-kind", "full-house", "flush", "straight",
        "three-of-a-kind", "two-pairs", "one-pair", "highest-card"
    };

    cout << "Hand: ";
    for (int i = 0; i < 5; i++)
        cout << cards[i] << " ";
    cout << "Deck: ";
    for (int i = 5; i < 10; i++)
        cout << cards[i] << " ";
    cout << "Best hand: " << hands[res] << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}