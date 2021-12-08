#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    int ballCount, wx, wy;
    cin >> ballCount >> wx >> wy;

    vector<int> x(ballCount), y(ballCount);
    for (int i = 0; i < ballCount; i++)
        cin >> x[i] >> y[i];

    int bestBall = 0;
    int bestDist = (wx - x[0]) * (wx - x[0]) + (wy - y[0]) * (wy - y[0]);
    for (int i = 1; i < ballCount; i++) {
        int dist = (wx - x[i]) * (wx - x[i]) + (wy - y[i]) * (wy - y[i]);
        if (bestDist > dist) {
            bestDist = dist;
            bestBall = i;
        }
    }

    cout << bestBall + 1 << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;
    
    for (int i = 0; i < n; i++)
        solve();
}