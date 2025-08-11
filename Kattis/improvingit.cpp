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

    int vertexCount, limit;
    cin >> vertexCount >> limit;
    vertexCount++;

    vector<long long> dist(vertexCount, 1e18);
    dist[0] = 0;

    for (int a = 0; a < vertexCount - 1; a++) {
        int buyPrice;
        cin >> buyPrice;

        for (int b = a + 1; b < vertexCount && b <= a + limit; b++) {
            int sellPrice;
            cin >> sellPrice;

            dist[b] = min(dist[b], dist[a] + buyPrice - sellPrice);
        }
    }

    cout << dist.back();
}