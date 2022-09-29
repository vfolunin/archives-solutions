#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool dfs(vector<vector<int>> &graphA, int vFromA, vector<int> &visited, vector<int> &pairFromA) {
    visited[vFromA] = 1;

    for (int vFromB : graphA[vFromA]) {
        int &toFromA = pairFromA[vFromB];

        if (toFromA == -1 || !visited[toFromA] && dfs(graphA, toFromA, visited, pairFromA)) {
            toFromA = vFromA;
            return 1;
        }
    }

    return 0;
}

vector<int> kuhn(vector<vector<int>> &graphA, int vertexCountB) {
    vector<int> pairFromA(vertexCountB, -1);

    for (int vFromA = 0; vFromA < graphA.size(); vFromA++) {
        vector<int> visited(graphA.size());
        dfs(graphA, vFromA, visited, pairFromA);
    }

    return pairFromA;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int h, w, y1, x1, y2, x2;
    cin >> h >> w >> y1 >> x1 >> y2 >> x2;
    y1--;
    x1--;
    y2--;
    x2--;

    vector<vector<int>> graphA(h * w);

    for (int y = 0; y < h; y++) {
        for (int x = 0; x < w; x++) {
            if ((y + x) % 2 && (y != y1 || x != x1) && (y != y2 || x != x2)) {
                static vector<int> dy = { -1, 0, 1, 0 };
                static vector<int> dx = { 0, 1, 0, -1 };

                for (int d = 0; d < dy.size(); d++) {
                    int ty = y + dy[d];
                    int tx = x + dx[d];

                    if (0 <= ty && ty < h && 0 <= tx && tx < w && 
                        (ty != y1 || tx != x1) && (ty != y2 || tx != x2))
                        graphA[y * w + x].push_back(ty * w + tx);
                }
            }
        }
    }

    vector<int> pairFromA = kuhn(graphA, h * w);
    int matchingSize = pairFromA.size() - count(pairFromA.begin(), pairFromA.end(), -1);

    cout << (matchingSize * 2 == h * w - 2 ? "YES" : "NO");
}