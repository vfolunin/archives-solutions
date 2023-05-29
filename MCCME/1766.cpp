#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <array>
#include <set>
#include <map>
#include <string>
using namespace std;

string bfs(int n) {
    vector<vector<array<int, 3>>> from(n + 1, vector<array<int, 3>>(n + 1, { -1, -1, -1 }));

    queue<pair<int, int>> q;
    q.push({ 0, 0 });

    while (!q.empty()) {
        auto [sum, remainder] = q.front();
        q.pop();

        if (sum == n && !remainder)
            break;

        for (int digit = 0; digit <= 9; digit++) {
            int toSum = sum + digit;
            int toRemainder = ((remainder * 10) + digit) % n;

            if (toSum <= n && from[toSum][toRemainder][0] == -1) {
                q.push({ toSum, toRemainder });
                from[toSum][toRemainder] = { sum, remainder, digit };
            }
        }
    }

    string res;
    for (int sum = n, remainder = 0; sum || remainder; ) {
        auto &[prevSum, prevRemainder, digit] = from[sum][remainder];
        res.push_back(digit + '0');
        sum = prevSum;
        remainder = prevRemainder;
    }
    return { res.rbegin(), res.rend() };
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    cout << bfs(n);
}