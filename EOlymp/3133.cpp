#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    vector<double> dist, fuel;
    while (1) {
        double curDist, curFuel;
        cin >> curDist >> curFuel;

        if (curDist == -1)
            return 0;

        if (!curDist)
            break;

        dist.push_back(curDist);
        fuel.push_back(curFuel);
    }

    double totalDist = 0;
    double totalFuel = 0;

    for (int i = 1; i < dist.size(); i++) {
        if (fuel[i - 1] > fuel[i]) {
            totalDist += dist[i] - dist[i - 1];
            totalFuel += fuel[i - 1] - fuel[i];
        }
    }

    cout.precision(0);
    cout << fixed << fuel.back() / totalFuel * totalDist << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}