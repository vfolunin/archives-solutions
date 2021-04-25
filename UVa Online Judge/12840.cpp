#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve(int test) {
    int itemCount, targetSum;
    cin >> itemCount >> targetSum;

    vector<int> items(itemCount);
    for (int &x : items)
        cin >> x;

    vector<vector<int>> minItems(itemCount + 1, vector<int>(targetSum + 1, 1e9));
    minItems[0][0] = 0;

    for (int i = 1; i <= itemCount; i++) {
        minItems[i] = minItems[i - 1];
        for (int sum = 0; sum + items[i - 1] <= targetSum; sum++)
            minItems[i][sum + items[i - 1]] = min(minItems[i][sum + items[i - 1]], minItems[i][sum] + 1);
    }
    
    cout << "Case " << test << ": ";

    if (minItems[itemCount][targetSum] == 1e9) {
        cout << "impossible\n";
        return;
    }

    cout << "[" << minItems[itemCount][targetSum] << "]";
    for (int sum = targetSum, i = itemCount; i > 0; i--) {
        while (sum >= items[i - 1] && minItems[i][sum] - 1 == minItems[i][sum - items[i - 1]]) {
            cout << " " << items[i - 1];
            sum -= items[i - 1];
        }
    }
    cout << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int test = 1; test <= n; test++)
        solve(test);
}