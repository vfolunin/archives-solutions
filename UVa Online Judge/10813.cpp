#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void mark(vector<vector<int>> &card, int number) {
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
            if (card[i][j] == number)
                card[i][j] = 0;
}

bool win(vector<vector<int>> &card) {
    for (int i = 0; i < 5; i++) {
        if (!card[i][0] && !card[i][1] && !card[i][2] && !card[i][3] && !card[i][4])
            return 1;
        if (!card[0][i] && !card[1][i] && !card[2][i] && !card[3][i] && !card[4][i])
            return 1;
    }
    if (!card[0][0] && !card[1][1] && !card[2][2] && !card[3][3] && !card[4][4])
        return 1;
    if (!card[0][4] && !card[1][3] && !card[2][2] && !card[3][1] && !card[4][0])
        return 1;
    return 0;
}

void solve() {
    vector<vector<int>> card(5, vector<int>(5));
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
            if (i != 2 || j != 2)
                cin >> card[i][j];

    vector<int> numbers(75);
    for (int &n : numbers)
        cin >> n;

    for (int i = 0; i < numbers.size(); i++) {
        mark(card, numbers[i]);
        if (win(card)) {
            cout << "BINGO after " << i + 1 << " numbers announced\n";
            break;
        }
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}