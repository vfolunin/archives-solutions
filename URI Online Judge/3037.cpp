#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    int aScore = 0;
    for (int i = 0; i < 3; i++) {
        int x, d;
        cin >> x >> d;
        aScore += x * d;
    }

    int bScore = 0;
    for (int i = 0; i < 3; i++) {
        int x, d;
        cin >> x >> d;
        bScore += x * d;
    }

    cout << (aScore >= bScore ? "JOAO\n" : "MARIA\n");
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}