#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    int clientCount;
    cin >> clientCount;

    vector<double> time(clientCount);
    for (double &t : time) {
        int pieceCount;
        cin >> pieceCount;

        for (int i = 0; i < pieceCount; i++) {
            int pieceSize;
            cin >> pieceSize;
            t += pieceSize;
        }
    }

    sort(time.begin(), time.end());
    double curTime = 0, sum = 0;

    for (double t : time) {
        curTime += t;
        sum += curTime;
    }

    cout << fixed << sum / clientCount << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}