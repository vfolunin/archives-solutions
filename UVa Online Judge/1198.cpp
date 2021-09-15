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

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int vertexCount;
    cin >> vertexCount;
    cin.ignore();

    vector<vector<int>> dist(vertexCount, vector<int>(vertexCount, 1e9));

    for (int v = 0; v < vertexCount; v++)
        dist[v][v] = 0;

    for (int v = 0; v < vertexCount; v++) {
        for (int to : readInts()) {
            to--;
            dist[v][to] = dist[to][v] = 1;
        }
    }

    for (int v = 0; v < vertexCount; v++)
        for (int a = 0; a < vertexCount; a++)
            for (int b = 0; b < vertexCount; b++)
                dist[a][b] = min(dist[a][b], dist[a][v] + dist[v][b]);

    int queryCount;
    cin >> queryCount;
    cin.ignore();

    for (int i = 0; i < queryCount; i++) {
        vector<int> vSet = readInts();
        bool geodeticS = 1;
        
        for (int v = 0; geodeticS && v < vertexCount; v++) {
            bool geodeticV = 0;
            for (int a : vSet) {
                a--;
                for (int b : vSet) {
                    b--;
                    geodeticV |= dist[a][v] + dist[v][b] == dist[a][b];
                }
            }
            geodeticS &= geodeticV;
        }

        cout << (geodeticS ? "yes\n" : "no\n");
    }
}