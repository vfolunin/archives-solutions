#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve(int test) {
    int gameCount;
    cin >> gameCount;

    string gameResult(gameCount, ' ');
    for (int i = 0; i < gameCount; i++) {
        cin >> gameResult[i];
        if (gameResult[i] == 'D')
            gameResult[i] = 'L';
    }

    int pos = gameResult.find("LLL");

    cout << "Case " << test << ": ";
    if (pos == -1)
        cout << "Yay! Mighty Rafa persists!\n";
    else
        cout << pos + 3 << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int test = 1; test <= n; test++)
        solve(test);
}