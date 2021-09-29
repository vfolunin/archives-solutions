#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    int heroCount, towerCount, dmg;
    cin >> heroCount >> towerCount >> dmg;

    long long hitCount = 0;

    for (int i = 0; i < heroCount; i++) {
        int hp;
        cin >> hp;
        hitCount += (hp - 1) / dmg;
    }

    cout << (hitCount >= towerCount ? "YES\n" : "NO\n");
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}