#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int rec(vector<int> cardCount) {
    static map<vector<int>, int> memo;
    if (memo.count(cardCount))
        return memo[cardCount];

    int sum = 0;
    for (int i = 0; i < 6; i++)
        sum += (4 - cardCount[i]) * (i + 1);

    if (sum == 31)
        return memo[cardCount] = 2;

    for (int i = 0; i < 6; i++) {
        if (cardCount[i] && sum + i + 1 <= 31) {
            cardCount[i]--;
            int r = rec(cardCount);
            cardCount[i]++;
            if (r == 2)
                return memo[cardCount] = 1;
        }
    }

    return memo[cardCount] = 2;
}

bool solve() {
    string s;
    if (!(cin >> s))
        return 0;

    vector<int> cardCount(6, 4);
    for (char c : s)
        cardCount[c - '1']--;

    int res = rec(cardCount);
    if (s.size() % 2)
        res = 3 - res;

    cout << s << " " << (res == 1 ? "A\n" : "B\n");
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}