#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool canMove(string &a, string &b) {
    return a[0] == b[0] || a[1] == b[1];
}

pair<int, int> findMove(vector<vector<string>> &piles) {
    for (int i = 1; i < piles.size(); i++) {
        if (i >= 3 && canMove(piles[i].back(), piles[i - 3].back()))
            return { i, i - 3 };
        if (canMove(piles[i].back(), piles[i - 1].back()))
            return { i, i - 1 };
    }
    return { -1, -1 };
}

void move(vector<vector<string>> &piles, int from, int to) {
    piles[to].push_back(piles[from].back());
    piles[from].pop_back();
    if (piles[from].empty())
        piles.erase(piles.begin() + from);
}

bool solve() {
    vector<vector<string>> piles(52, vector<string>(1));
    cin >> piles[0][0];
    if (piles[0][0] == "#")
        return 0;

    for (int i = 1; i < 52; i++)
        cin >> piles[i][0];

    while (1) {
        auto [from, to] = findMove(piles);
        if (from == -1)
            break;
        move(piles, from, to);
    }

    cout << piles.size() << " pile" << (piles.size() > 1 ? "s" : "") << " remaining: ";
    for (int pos = 0; pos < piles.size(); pos++)
        cout << piles[pos].size() << (pos + 1 < piles.size() ? ' ' : '\n');
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}