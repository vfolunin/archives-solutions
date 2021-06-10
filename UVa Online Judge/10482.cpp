#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve(int test) {
    int itemCount;
    cin >> itemCount;

    int sum = 0;
    vector<int> weights(itemCount);
    for (int &weight : weights) {
        cin >> weight;
        sum += weight;
    }

    vector<vector<int>> can(sum + 1, vector<int>(sum + 1));
    can[0][0] = 1;

    for (int weight : weights) {
        auto nextCan = can;
        for (int a = 0; a <= sum; a++) {
            for (int b = 0; b <= sum; b++) {
                if (can[a][b]) {
                    if (a + weight <= sum)
                        nextCan[a + weight][b] = 1;
                    if (b + weight <= sum)
                        nextCan[a][b + weight] = 1;
                }
            }
        }
        can.swap(nextCan);
    }

    int res = 1e9;
    for (int a = 0; a <= sum; a++)
        for (int b = 0, c = sum - a - b; a + b <= sum; b++, c--)
            if (can[a][b])
                res = min(res, max(max(abs(a - b), abs(a - c)), abs(b - c)));

    cout << "Case " << test << ": " << res << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int test = 1; test <= n; test++)
        solve(test);
}