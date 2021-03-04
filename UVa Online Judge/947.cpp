#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool hasZero(int n) {
    while (n) {
        if (n % 10 == 0)
            return 1;
        n /= 10;
    }
    return 0;
}

pair<int, int> check(int a, int b) {
    int bulls = 0, cows = 0;
    vector<int> aDigits(10), bDigits(10);
    for (; a; a /= 10, b /= 10) {
        if (a % 10 == b % 10) {
            bulls++;
        } else {
            aDigits[a % 10]++;
            bDigits[b % 10]++;
        }
    }
    for (int i = 1; i < 10; i++)
        cows += min(aDigits[i], bDigits[i]);
    return { bulls, cows };
}

void solve() {
    int guess, bulls, cows;
    cin >> guess >> bulls >> cows;

    int limit = 9;
    while (limit < guess)
        limit = limit * 10 + 9;
    
    int res = 0;
    for (int i = limit / 9; i <= limit; i++) {
        if (hasZero(i))
            continue;
        auto [iBulls, iCows] = check(guess, i);
        res += iBulls == bulls && iCows == cows;
    }

    cout << res << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}