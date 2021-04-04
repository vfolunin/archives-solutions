#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool compare(string &a, string &b) {
    static string suits = "CDSH";
    int sa = suits.find(a[0]), sb = suits.find(b[0]);
    if (sa != sb)
        return sa < sb;
    static string values = "23456789TJQKA";
    int va = values.find(a[1]), vb = values.find(b[1]);
    return va < vb;
}

bool solve() {
    char dealer;
    cin >> dealer;

    if (dealer == '#')
        return 0;

    string sides = "SWNE";

    vector<vector<string>> hand(4);
    for (int i = 0, d = (sides.find(dealer) + 1) % 4; i < 52; i++, d = (d + 1) % 4) {
        char suit, value;
        cin >> suit >> value;
        hand[d].push_back(string() + suit + value);
    }

    for (int i = 0; i < 4; i++) {
        sort(hand[i].begin(), hand[i].end(), compare);
        cout << sides[i] << ":";
        for (string &card : hand[i])
            cout << " " << card;
        cout << "\n";
    }
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}