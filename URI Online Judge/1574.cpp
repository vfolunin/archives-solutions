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

    vector<int> moves(moveCount);
    int pos = 0;

    for (int &move : moves) {
        string op;
        cin >> op;

        if (op == "LEFT") {
            move = -1;
        } else if (op == "RIGHT") {
            move = 1;
        } else {
            int index;
            cin >> op >> index;
            move = moves[index - 1];
        }

        pos += move;
    }

    cout << pos << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}