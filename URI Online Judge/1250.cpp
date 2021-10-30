#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    int shotCount;
    cin >> shotCount;

    vector<int> height(shotCount);
    for (int &h : height)
        cin >> h;

    string move;
    cin >> move;

    int hitCount = 0;
    for (int i = 0; i < shotCount; i++)
        hitCount += height[i] <= 2 ^ move[i] == 'J';

    cout << hitCount << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}