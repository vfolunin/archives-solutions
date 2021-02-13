#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool compareBlocks(vector<int> &a, vector<int> &b) {
    return a[0] * a[1] > b[0] * b[1];
}

bool solve() {
    int a, b, t;
    if (!(cin >> a >> b >> t))
        return 0;

    vector<int> maxBurgers(t + 1, -1);
    maxBurgers[0] = 0;

    for (int i = 0; i <= t; i++) {
        if (i >= a && maxBurgers[i - a] != -1)
            maxBurgers[i] = max(maxBurgers[i], maxBurgers[i - a] + 1);
        if (i >= b && maxBurgers[i - b] != -1)
            maxBurgers[i] = max(maxBurgers[i], maxBurgers[i - b] + 1);
    }

    if (maxBurgers[t] != -1) {
        cout << maxBurgers[t] << "\n";
    } else {
        int beerTime = 0;
        while (maxBurgers[t] == -1) {
            t--;
            beerTime++;
        }
        cout << maxBurgers[t] << " " << beerTime << "\n";
    }
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}