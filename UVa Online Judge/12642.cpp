#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    int cardCount;
    unsigned long long roundCount;
    if (!(cin >> cardCount >> roundCount))
        return 0;

    vector<vector<int>> to(cardCount, vector<int>(64));
    for (int i = 0; i < cardCount; i++) {
        cin >> to[i][0];
        to[i][0]--;
    }
    for (int p = 1; p < 64; p++)
        for (int i = 0; i < cardCount; i++)
            to[i][p] = to[to[i][p - 1]][p - 1];
    
    for (int i = 0; i < cardCount; i++) {
        int position = i;
        unsigned long long r = roundCount;
        for (int p = 63; p >= 0; p--) {
            if (r >= 1ULL << p) {
                r -= 1ULL << p;
                position = to[position][p];
            }
        }
        cout << position + 1 << (i + 1 < cardCount ? " " : "\n");
    }
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}