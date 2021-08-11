#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve(int test) {
    string s;
    cin >> s;

    int hat = 0, hatScore = 0, hatScoreHat = 0, convertableScore = 0;

    for (char c : s) {
        if (c == '^') {
            if (hatScore) {
                hatScore--;
                hatScoreHat++;
            } else if (convertableScore) {
                convertableScore--;
                hatScore++;
            } else {
                hat++;
            }
        } else {
            if (hat) {
                hat--;
                hatScore++;
            } else {
                convertableScore = min(convertableScore + 1, hatScoreHat);
            }
        }
    }

    cout << "Case " << test << ": " << hatScoreHat << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int test = 1; test <= n; test++)
        solve(test);
}