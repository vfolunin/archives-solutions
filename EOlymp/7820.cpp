#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
using namespace std;

long long bfs(int targetSum) {
    vector<vector<long long>> dist(targetSum + 1, vector<long long>(targetSum, 1e18));
    queue<pair<int, int>> q;

    dist[0][0] = 0;
    q.push({ 0, 0 });

    while (!q.empty()) {
        auto [sum, remainder] = q.front();
        q.pop();

        if (sum == targetSum && !remainder)
            return dist[sum][remainder];

        for (int digit = !sum; digit <= 9; digit++) {
            int tSum = sum + digit;
            int tRemainder = (remainder * 10 + digit) % targetSum;
            long long candidate = dist[sum][remainder] * 10 + digit;

            if (tSum <= targetSum && dist[tSum][tRemainder] > candidate) {
                dist[tSum][tRemainder] = candidate;
                q.push({ tSum, tRemainder });
            }
        }
    }

    return 1e18;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int targetSum;
    cin >> targetSum;

    cout << bfs(targetSum);
}