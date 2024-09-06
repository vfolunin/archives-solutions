#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    int throwCount;
    cin >> throwCount;

    int score = 0;
    for (int i = 0; i < throwCount; i++) {
        int x, y;
        cin >> x >> y;

        for (int points = 10; points; points--) {
            int r = 20 * (11 - points);
            if (x * x + y * y <= r * r) {
                score += points;
                break;
            }
        }
    }

    cout << score << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}