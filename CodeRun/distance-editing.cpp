#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int editDistance(string &a, string &b, int priceAdd, int priceRemove, int priceChange) {
    vector<vector<int>> dist(a.size() + 1, vector<int>(b.size() + 1));

    for (int ai = 1; ai <= a.size(); ai++)
        dist[ai][0] = ai * priceRemove;

    for (int bi = 1; bi <= b.size(); bi++)
        dist[0][bi] = bi * priceAdd;

    for (int ai = 1; ai <= a.size(); ai++) {
        for (int bi = 1; bi <= b.size(); bi++) {
            if (a[ai - 1] == b[bi - 1])
                dist[ai][bi] = dist[ai - 1][bi - 1];
            else
                dist[ai][bi] = min({ dist[ai - 1][bi] + priceRemove, dist[ai][bi - 1] + priceAdd, dist[ai - 1][bi - 1] + priceChange });
        }
    }

    return dist[a.size()][b.size()];
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    string a, b;
    int priceAdd, priceRemove, priceChange;
    cin >> a >> a >> a >> b >> priceAdd >> priceRemove >> priceChange;

    cout << editDistance(a, b, priceAdd, priceRemove, priceChange);
}