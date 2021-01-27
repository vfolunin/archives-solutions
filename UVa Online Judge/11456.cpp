#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    int carCount;
    cin >> carCount;

    vector<int> cars(carCount);
    for (int &weight : cars)
        cin >> weight;

    vector<int> lis(carCount, 1), lds(carCount, 1);
    int res = 0;

    for (int i = carCount - 1; i >= 0; i--) {
        for (int j = carCount - 1; j > i; j--) {
            if (cars[j] < cars[i])
                lis[i] = max(lis[i], lis[j] + 1);
            if (cars[j] > cars[i])
                lds[i] = max(lds[i], lds[j] + 1);
        }
        res = max(res, lis[i] + lds[i] - 1);
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