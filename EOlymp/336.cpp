#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    int size, moveCount;
    if (!(cin >> size >> moveCount))
        return 0;

    vector<int> moves(moveCount);
    for (int &move : moves)
        cin >> move;

    vector<int> res(size + 1, 2);
    for (int i = 1; i < res.size(); i++)
        for (int move : moves)
            if (i >= move && res[i - move] == 2)
                res[i] = 1;

    cout << res.back();
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}