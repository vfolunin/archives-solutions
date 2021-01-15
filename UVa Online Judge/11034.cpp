#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
using namespace std;

int getMoves(queue<int> &q, int limit) {
    int sum = 0, moves = 0;
    while (!q.empty()) {
        if (sum + q.front() <= limit) {
            sum += q.front();
        } else {
            moves++;
            sum = q.front();
        }
        q.pop();
    }
    return moves + (sum > 0);
}

void solve() {
    int width, carCount;
    cin >> width >> carCount;
    width *= 100;

    queue<int> l, r;
    for (int i = 0; i < carCount; i++) {
        int carWidth;
        string bank;
        cin >> carWidth >> bank;
        if (bank == "left")
            l.push(carWidth);
        else
            r.push(carWidth);
    }

    int lMoves = max(0, getMoves(l, width) * 2 - 1);
    int rMoves = getMoves(r, width) * 2;
    cout << max(lMoves, rMoves) << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}