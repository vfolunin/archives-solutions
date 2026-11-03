#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    vector dist(5, vector<int>(5));
    for (int a = 0; a < dist.size(); a++)
        for (int b = 0; b < dist.size(); b++)
            cin >> dist[a][b];

    vector<int> order = { 0, 1, 2, 3, 4 }, resOrder;
    int resDist = 1e9;

    do {
        if (order[3] == 2)
            continue;

        int totalDist = 0;
        for (int i = 0; i + 1 < order.size(); i++)
            totalDist += dist[order[i]][order[i + 1]];

        if (resDist > totalDist) {
            resOrder = order;
            resDist = totalDist;
        }
    } while (next_permutation(order.begin() + 1, order.begin() + 4));

    cout << resDist << "\n";
    for (int v : resOrder)
        cout << v + 1 << " ";
}