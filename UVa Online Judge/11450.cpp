#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    int money, itemTypeCount;
    cin >> money >> itemTypeCount;

    vector<vector<int>> can(2, vector<int>(money + 1));
    can[0][0] = 1;

    for (int i = 0; i < itemTypeCount; i++) {
        int itemCount;
        cin >> itemCount;
        for (int j = 0; j < itemCount; j++) {
            int price;
            cin >> price;
            for (int sum = price; sum <= money; sum++)
                if (can[0][sum - price])
                    can[1][sum] = 1;
        }
        can[0].swap(can[1]);
        fill(can[1].begin(), can[1].end(), 0);
    }

    while (money >= 0 && !can[0][money])
        money--;

    if (money >= 0)
        cout << money << "\n";
    else
        cout << "no solution\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}