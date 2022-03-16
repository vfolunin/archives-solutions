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

    vector<string> cards(12);
    for (string &card : cards)
        cin >> card;

    vector<vector<int>> sets;
    for (int a = 0; a < cards.size(); a++) {
        for (int b = a + 1; b < cards.size(); b++) {
            for (int c = b + 1; c < cards.size(); c++) {
                bool set = 1;
                for (int i = 0; i < cards[a].size(); i++)
                    set &= (cards[a][i] == cards[b][i] && cards[a][i] == cards[c][i]) ||
                           (cards[a][i] != cards[b][i] && cards[a][i] != cards[c][i] && cards[b][i] != cards[c][i]);
                if (set)
                    sets.push_back({ a, b, c });
            }
        }
    }

    if (!sets.empty()) {
        for (vector<int> &set : sets) {
            for (int index : set)
                cout << index + 1 << " ";
            cout << "\n";
        }
    } else {
        cout << "no sets\n";
    }
}