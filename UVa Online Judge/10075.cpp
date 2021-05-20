#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

double globeDist(double lat1, double lon1, double lat2, double lon2) {
    static const double R = 6378;
    double angle = acos(sin(lat1) * sin(lat2) + cos(lat1) * cos(lat2) * cos(lon1 - lon2));
    return R * angle;
}

bool solve(int test) {
    int vertexCount, edgeCount, queryCount;
    cin >> vertexCount >> edgeCount >> queryCount;

    if (!vertexCount)
        return 0;
    
    map<string, int> vertexId;
    vector<double> lat(vertexCount), lon(vertexCount);
    static const double PI = 3.141592653589793;

    for (int v = 0; v < vertexCount; v++) {
        string name;
        cin >> name >> lat[v] >> lon[v];
        vertexId[name] = v;
        lat[v] *= PI / 180;
        lon[v] *= PI / 180;
    }

    vector<vector<int>> dist(vertexCount, vector<int>(vertexCount, 1e9));
    for (int v = 0; v < vertexCount; v++)
        dist[v][v] = 0;
    for (int i = 0; i < edgeCount; i++) {
        string sa, sb;
        cin >> sa >> sb;
        int a = vertexId[sa], b = vertexId[sb];
        dist[a][b] = round(globeDist(lat[a], lon[a], lat[b], lon[b]));
    }

    for (int v = 0; v < vertexCount; v++)
        for (int a = 0; a < vertexCount; a++)
            for (int b = 0; b < vertexCount; b++)
                dist[a][b] = min(dist[a][b], dist[a][v] + dist[v][b]);

    if (test > 1)
        cout << "\n";
    cout << "Case #" << test << "\n";
    for (int i = 0; i < queryCount; i++) {
        string sa, sb;
        cin >> sa >> sb;
        int a = vertexId[sa], b = vertexId[sb];
        
        if (dist[a][b] == 1e9)
            cout << "no route exists\n";
        else
            cout << dist[a][b] << " km\n";
    }
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    for (int test = 1; solve(test); test++);
}