#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

vector<int> readInts() {
    string line;
    getline(cin, line);
    stringstream ss(line);
    vector<int> res;
    int x;
    while (ss >> x)
        res.push_back(x);
    return res;
}

int rec(vector<vector<int>> &dist, vector<int> &route, int mask, int lastIndex, vector<vector<int>> &memo) {
    int &res = memo[mask][lastIndex];
    if (res != -1)
        return res;

    int last = route[1 + lastIndex];
    if (!(mask & (mask - 1)))
        return res = (dist[route[0]][last] ? dist[route[0]][last] : 1e9);

    res = 1e9;
    for (int prevIndex = 0; prevIndex < route.size() - 2; prevIndex++) {
        if (prevIndex == lastIndex || !(mask & (1 << prevIndex)))
            continue;
        int prevMask = mask ^ (1 << lastIndex);
        int prev = route[1 + prevIndex];
        if (dist[prev][last])
            res = min(res, rec(dist, route, prevMask, prevIndex, memo) + dist[prev][last]);
    }
    return res;
}

void solve(vector<vector<int>> &dist) {
    vector<int> route = readInts();
    for (int &v : route)
        v--;

    if (route.size() == 2) {
        cout << dist[route[0]][route[1]] << "\n";
        return;
    }

    int n = route.size() - 2;
    vector<vector<int>> memo(1 << n, vector<int>(n, -1));

    int res = 1e9;
    for (int lastIndex = 0; lastIndex < n; lastIndex++) {
        int last = route[1 + lastIndex];
        if (dist[last][route.back()])
            res = min(res, rec(dist, route, (1 << n) - 1, lastIndex, memo) + dist[last][route.back()]);
    }
    
    cout << (res != 1e9 ? res : 0) << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int vertexCount, routeCount;
    cin >> vertexCount >> routeCount;

    vector<vector<int>> dist(vertexCount, vector<int>(vertexCount));
    for (vector<int> &row : dist)
        for (int &d : row)
            cin >> d;

    cin.ignore();

    for (int i = 0; i < routeCount; i++)
        solve(dist);
}