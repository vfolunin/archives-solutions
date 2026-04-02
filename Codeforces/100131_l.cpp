#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
using namespace std;

void printPath(vector<pair<int, int>> &from, int start, int finish) {
    vector<int> path;
    for (int v = finish; v != start; v = from[v].first)
        path.push_back(from[v].second);
    reverse(path.begin(), path.end());
    for (int v : path)
        cout << v;
}

void bfs(string &s, vector<int> &digits, int divisor) {
    vector<int> dist(divisor, 1e9);
    vector<pair<int, int>> from(divisor, { -1, -1 });
    queue<int> q;

    int start = 0;
    for (char c : s)
        start = (start * 10 + c - '0') % divisor;

    dist[start] = 0;
    q.push(start);

    while (!q.empty()) {
        int v = q.front();
        q.pop();

        if (v == 0) {
            cout << s;
            printPath(from, start, v);
            return;
        }

        for (int digit : digits) {
            int to = (v * 10 + digit) % divisor;
            if (dist[to] > dist[v] + 1) {
                dist[to] = dist[v] + 1;
                from[to] = { v, digit };
                q.push(to);
            }
        }
    }

    cout << -1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    string s;
    int divisor, digitCount;
    cin >> s >> divisor >> digitCount;

    vector<int> digits(digitCount);
    for (int &digit : digits)
        cin >> digit;
    sort(digits.begin(), digits.end());

    bfs(s, digits, divisor);
}