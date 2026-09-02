#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

using Matrix = vector<vector<long long>>;

Matrix operator * (const Matrix &a, const Matrix &b) {
    Matrix res(a.size(), vector<long long>(b[0].size(), 2e18));
    for (int y = 0; y < res.size(); y++)
        for (int x = 0; x < res[0].size(); x++)
            for (int i = 0; i < a[0].size(); i++)
                res[y][x] = min(res[y][x], a[y][i] + b[i][x]);
    return res;
}

Matrix pow(const Matrix &m, long long p) {
    if (p == 1)
        return m;
    if (p % 2)
        return pow(m, p - 1) * m;
    Matrix r = pow(m, p / 2);
    return r * r;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int vertexCount, edgeCount, targetEdgeCount;
    cin >> vertexCount >> edgeCount >> targetEdgeCount;

    Matrix dist(vertexCount, vector<long long>(vertexCount, 2e18));
    for (int i = 0; i < edgeCount; i++) {
        int a, b, weight;
        cin >> a >> b >> weight;
        a--;
        b--;
        dist[a][b] = min<long long>(dist[a][b], weight);
    }

    dist = pow(dist, targetEdgeCount);

    cout << (dist[0][vertexCount - 1] != 2e18 ? dist[0][vertexCount - 1] : -1);
}