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

    int size;
    cin >> size;

    vector<vector<int>> dist(size, vector<int>(size));
    for (int a = 0; a < size; a++)
        for (int b = 0; b < size; b++)
            cin >> dist[a][b];

    int resDist = 1e9;
    for (int a = 0; a < size; a++)
        for (int b = 0; b < size; b++)
            for (int c = 0; c < size; c++)
                if (a != b && a != c && b != c && resDist > dist[a][b] + dist[b][c] + dist[c][a])
                    resDist = dist[a][b] + dist[b][c] + dist[c][a];

    cout << resDist;
}