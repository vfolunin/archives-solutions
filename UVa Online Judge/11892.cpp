#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    int pileCount;
    cin >> pileCount;

    vector<int> piles(pileCount);
    for (int &pile : piles)
        cin >> pile;

    if (pileCount % 2 == 0 && count(piles.begin(), piles.end(), 1) == pileCount)
        cout << "piloop\n";
    else
        cout << "poopi\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}