#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <numeric>
using namespace std;

vector<int> bfs(vector<vector<int>> &graph, int start) {
    vector<int> dist(graph.size(), 1e9);
    queue<int> q;

    dist[start] = 0;
    q.push(start);

    while (!q.empty()) {
        int v = q.front();
        q.pop();

        for (int to : graph[v]) {
            if (dist[to] > dist[v] + 1) {
                dist[to] = dist[v] + 1;
                q.push(to);
            }
        }
    }

    return dist;
}

struct Fraction {
    long long num, den;

    Fraction(long long n = 0, long long d = 1) : num(n), den(d) {
        long long g = gcd(num, den);
        num /= g;
        den /= g;

        if (den < 0) {
            num = -num;
            den = -den;
        }
    }

    bool operator < (const Fraction &that) const {
        return num * that.den < that.num * den;
    }

    Fraction operator + (const Fraction &that) const {
        return { num * that.den + that.num * den, den * that.den };
    }

    Fraction operator / (const Fraction &that) const {
        return { num * that.den, den * that.num };
    }

    friend ostream &operator << (ostream &out, const Fraction &f) {
        return out << f.num << "/" << f.den;
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int vertexCount, edgeCount, wormholeCount;
    cin >> vertexCount >> edgeCount >> wormholeCount;

    vector<int> wormholes(wormholeCount);
    for (int &v : wormholes) {
        cin >> v;
        v--;
    }

    vector<vector<int>> graph(vertexCount);
    for (int i = 0; i < edgeCount; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    vector<int> distFromStart = bfs(graph, 0);
    vector<int> distToFinish = bfs(graph, vertexCount - 1);

    long long distFromWormholes = 0;
    for (int &v : wormholes)
        distFromWormholes += distToFinish[v];

    Fraction res = distFromStart.back();
    for (int &v : wormholes)
        res = min(res, Fraction(distFromWormholes - distToFinish[v], wormholeCount - 1) + distFromStart[v]);

    cout << res;
}