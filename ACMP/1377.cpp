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

    int vertexCount;
    cin >> vertexCount;

    vector<int> dist(vertexCount, 1e9);
    dist[0] = 0;

    while (1) {
        bool updated = 0;
        for (int a = 0; a < vertexCount; a++) {
            for (int b = a + 1; b < vertexCount; b++) {
                int w = (179 * (a + 1) + 719 * (b + 1)) % 1000 - 500;
                if (dist[a] != 1e9 && dist[b] > dist[a] + w) {
                    dist[b] = dist[a] + w;
                    updated = 1;
                }
            }
        }
        if (!updated)
            break;
    }

    cout << dist.back();
}