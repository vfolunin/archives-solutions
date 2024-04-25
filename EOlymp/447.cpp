#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
using namespace std;

void printPath(vector<vector<pair<int, int>>> &from, int remainder, int digit) {
    vector<int> path;
    while (remainder != -1) {
        path.push_back(digit);
        auto &[prevRemainder, prevDigit] = from[remainder][digit];
        remainder = prevRemainder;
        digit = prevDigit;
    }
    reverse(path.begin(), path.end());
    for (int digit : path)
        cout << digit;
}

void bfs(vector<int> &digits, int divisor) {
    vector<vector<int>> dist(divisor, vector<int>(10, 1e9));
    vector<vector<pair<int, int>>> from(divisor, vector<pair<int, int>>(10, { -1, -1 }));
    queue<pair<int, int>> q;

    for (int digit : digits) {
        if (!digit)
            continue;

        int to = digit % divisor;
        if (dist[to][digit] > 0) {
            dist[to][digit] = 0;
            from[to][digit] = { -1, -1 };
            q.push({ to, digit });
        }
    }

    while (!q.empty()) {
        auto [remainder, digit] = q.front();
        q.pop();

        if (remainder == 0) {
            printPath(from, remainder, digit);
            return;
        }

        for (int nextDigit : digits) {
            if (digit == nextDigit)
                continue;

            int nextRemainder = (remainder * 10 + nextDigit) % divisor;
            if (dist[nextRemainder][nextDigit] > dist[remainder][digit] + 1) {
                dist[nextRemainder][nextDigit] = dist[remainder][digit] + 1;
                from[nextRemainder][nextDigit] = { remainder, digit };
                q.push({ nextRemainder, nextDigit });
            }
        }
    }

    cout << -1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    string s;
    getline(cin, s);

    vector<int> digits;
    for (char c : s)
        digits.push_back(c - '0');

    int divisor;
    cin >> divisor;

    bfs(digits, divisor);
}