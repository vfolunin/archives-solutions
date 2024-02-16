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

    deque<int> cards(n);
    for (int i = 0; i < n; i++)
        cards[i] = i + 1;

    vector<int> discarded;
    while (cards.size() > 1) {
        discarded.push_back(cards.front());
        cards.pop_front();
        cards.push_back(cards.front());
        cards.pop_front();
    }

    cout << "Discarded cards:";
    for (int i = 0; i < discarded.size(); i++)
        cout << " " << discarded[i] << (i + 1 < discarded.size() ? "," : "");
    cout << "\nRemaining card: " << cards[0] << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}