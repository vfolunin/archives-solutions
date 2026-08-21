#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    vector<int> card(3);
    cin >> card[0] >> card[1] >> card[2];
    sort(card.begin(), card.end());

    if (!card[2])
        return 0;

    if (card[0] == card[2]) {
        if (card[0] == 13)
            cout << "*\n";
        else
            cout << card[0] + 1 << " " << card[0] + 1 << " " << card[0] + 1 << "\n";
    } else if (card[1] == card[2]) {
        if (card[0] == 12)
            cout << "1 1 1\n";
        else if (card[0] + 1 < card[1])
            cout << card[0] + 1 << " " << card[1] << " " << card[1] << "\n";
        else
            cout << card[1] << " " << card[1] << " " << card[0] + 2 << "\n";
    } else if (card[0] == card[1]) {
        if (card[2] == 13)
            cout << "1 " << card[0] + 1 << " " << card[0] + 1 << "\n";
        else
            cout << card[0] << " " << card[0] << " " << card[2] + 1 << "\n";
    } else {
        cout << "1 1 2\n";
    }
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}