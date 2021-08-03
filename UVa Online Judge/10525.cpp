#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve(int test) {
    int vertexCount, edgeCount;
    cin >> vertexCount >> edgeCount;

    vector<vector<long long>> dist1(vertexCount, vector<long long>(vertexCount, 1LL << 60));
    vector<vector<long long>> dist2(vertexCount, vector<long long>(vertexCount, 1LL << 60));
    for (int v = 0; v < vertexCount; v++)
        dist1[v][v] = dist2[v][v] = 0;

    for (int i = 0; i < edgeCount; i++) {
        int a, b;
        long long d1, d2;
        cin >> a >> b >> d1 >> d2;
        a--;
        b--;
        if (dist1[a][b] > d1 || dist1[a][b] == d1 && dist2[a][b] > d2) {
            dist1[a][b] = dist1[b][a] = d1;
            dist2[a][b] = dist2[b][a] = d2;
        }
    }

    for (int v = 0; v < vertexCount; v++) {
        for (int a = 0; a < vertexCount; a++) {
            for (int b = 0; b < vertexCount; b++) {
                long long d1 = dist1[a][v] + dist1[v][b], d2 = dist2[a][v] + dist2[v][b];
                if (dist1[a][b] > d1 || dist1[a][b] == d1 && dist2[a][b] > d2) {
                    dist1[a][b] = d1;
                    dist2[a][b] = d2;
                }
            }
        }
    }

    int queryCount;
    cin >> queryCount;

    if (test)
        cout << "\n";

    for (int i = 0; i < queryCount; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        if (dist1[a][b] != 1LL << 60)
            cout << "Distance and time to reach destination is " << dist2[a][b] << " & " << dist1[a][b] << ".\n";
        else
            cout << "No Path.\n";
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve(i);
}