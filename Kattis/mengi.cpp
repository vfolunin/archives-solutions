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

    sort(cards.begin(), cards.end());

    bool found = 0;
    for (int a = 0; a < cards.size(); a++) {
        for (int b = a + 1; b < cards.size(); b++) {
            for (int c = b + 1; c < cards.size(); c++) {
                bool ok = 1;
                for (int i = 0; i < cards[0].size() && ok; i++)
                    ok &= cards[a][i] == cards[b][i] && cards[a][i] == cards[c][i] ||
                          cards[a][i] != cards[b][i] && cards[a][i] != cards[c][i] && cards[b][i] != cards[c][i];

                if (ok) {
                    found = 1;
                    cout << cards[a] << " " << cards[b] << " " << cards[c] << "\n";
                }
            }
        }
    }

    if (!found)
        cout << "Engin Mengi";
}