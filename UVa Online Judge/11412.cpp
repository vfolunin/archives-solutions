#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

pair<int, int> check(string &guess, string &ans) {
    int bulls = 0, cows = 0;
    for (int i = 0; i < 4; i++) {
        if (guess[i] == ans[i])
            bulls++;
        else if (count(ans.begin(), ans.begin() + 4, guess[i]))
            cows++;
    }
    return { bulls, cows };
}

void solve() {
    string guessA, guessB;
    int bullsA, cowsA, bullsB, cowsB;
    cin >> guessA >> bullsA >> cowsA;
    cin >> guessB >> bullsB >> cowsB;

    string colors = "BGORVY";
    do {
        if (colors.substr(0, 4) == "ORVY")
            cout << "";
        auto [ba, ca] = check(guessA, colors);
        auto [bb, cb] = check(guessB, colors);
        if (ba == bullsA && ca == cowsA && bb == bullsB && cb == cowsB) {
            cout << "Possible\n";
            return;
        }
    } while (next_permutation(colors.begin(), colors.end()));

    cout << "Cheat\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}