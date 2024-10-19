#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    int itemCount, targetSum;
    cin >> itemCount >> targetSum;

    vector<int> items(itemCount);
    for (int &item : items)
        cin >> item;

    vector<int> dist(3601, 1e9);
    queue<int> q;

    dist[0] = 0;
    q.push(0);

    while (!q.empty()) {
        int sum = q.front();
        q.pop();

        for (int item : items) {
            int tSum = min(sum + item, 3600);
            if (0 <= tSum && dist[tSum] == 1e9) {
                dist[tSum] = dist[sum] + 1;
                q.push(tSum);
            }
        }
    }

    int minSum = targetSum;
    while (dist[minSum] == 1e9)
        minSum++;

    cout << dist[minSum] << " " << minSum - targetSum << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}