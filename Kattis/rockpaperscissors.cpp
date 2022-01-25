#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve(int test) {
    int playerCount, gameCount;
    if (!(cin >> playerCount >> gameCount))
        return 0;

    int roundCount = playerCount * (playerCount - 1) / 2 * gameCount;
    vector<double> games(playerCount), wins(playerCount);
    for (int i = 0; i < roundCount; i++) {
        int p1, p2;
        string s1, s2;
        cin >> p1 >> s1 >> p2 >> s2;
        p1--;
        p2--;

        static vector<string> signs = { "rock", "scissors", "paper" };
        int i1 = find(signs.begin(), signs.end(), s1) - signs.begin();
        int i2 = find(signs.begin(), signs.end(), s2) - signs.begin();

        if (i1 != i2) {
            games[p1]++;
            games[p2]++;
            if ((i1 + 1) % 3 == i2)
                wins[p1]++;
            if ((i1 + 2) % 3 == i2)
                wins[p2]++;
        }
    }

    if (test)
        cout << "\n";
    cout.precision(3);
    for (int i = 0; i < playerCount; i++) {
        if (games[i])
            cout << fixed << wins[i] / games[i] << "\n";
        else
            cout << "-\n";
    }
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    for (int i = 0; solve(i); i++);
}