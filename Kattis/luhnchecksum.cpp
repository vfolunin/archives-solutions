#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    string card;
    cin >> card;

    int sum = 0;
    for (int i = (int)card.size() - 2; i >= 0; i -= 2) {
        int value = 2 * (card[i] - '0');
        if (value > 9)
            value = value % 10 + 1;
        sum += value;
    }
    for (int i = (int)card.size() - 1; i >= 0; i -= 2)
        sum += card[i] - '0';

    cout << (sum % 10 ? "FAIL\n" : "PASS\n");
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}