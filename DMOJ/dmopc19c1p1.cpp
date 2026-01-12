#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    long long problemCount, win, lose, target;
    cin >> problemCount >> win >> lose >> target;

    win += lose;
    long long res = (target + problemCount * lose + win - 1) / win;

    cout << (res <= problemCount ? res : -1) << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}