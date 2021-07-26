#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct Solver {
    vector<vector<int>> pile;
    vector<vector<vector<vector<int>>>> memo;
    vector<int> inBasket, index;

    Solver() {
        int pileSize;
        cin >> pileSize;

        pile.assign(4, vector<int>(pileSize));
        for (int j = pileSize - 1; j >= 0; j--)
            for (int i = 0; i < 4; i++)
                cin >> pile[i][j];

        memo.assign(41, vector<vector<vector<int>>>(41, vector<vector<int>>(41, vector<int>(41, -1))));
        inBasket.resize(21);
        index.assign(4, pileSize);
    }

    int rec() {
        int &res = memo[index[0]][index[1]][index[2]][index[3]];
        if (res != -1)
            return res;

        int basketSize = count(inBasket.begin(), inBasket.end(), 1);
        if (basketSize == 5)
            return res = 0;

        res = 0;
        for (int i = 0; i < 4; i++) {
            if (!index[i])
                continue;

            int val = pile[i][index[i] - 1];
            index[i]--;
            inBasket[val] ^= 1;

            res = max(res, rec() + !inBasket[val]);

            index[i]++;
            inBasket[val] ^= 1;
        }
        return res;
    }
};

bool solve() {
    Solver solver;
    if (solver.pile[0].empty())
        return 0;

    cout << solver.rec() << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}