#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    int moveCount;
    cin >> moveCount;

    vector<pair<int, int>> moves(moveCount);
    for (auto &[start, finish] : moves)
        cin >> start;
    for (auto &[start, finish] : moves)
        cin >> finish;

    sort(moves.begin(), moves.end());

    for (int i = 0; i + 1 < moves.size(); i++) {
        if (moves[i].first == moves[i + 1].first ||
            moves[i].second >= moves[i + 1].second) {
            cout << "NO\n";
            return;
        }
    }

    cout << "YES\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int testCount;
    cin >> testCount;

    for (int test = 0; test < testCount; test++)
        solve();
}