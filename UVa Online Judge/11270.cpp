#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

vector<vector<vector<int>>> prepare() {
    vector<vector<vector<int>>> graph(11);
    
    for (int h = 1; h < graph.size(); h++) {
        graph[h].resize(1 << h);
    
        for (int a = 0; a < (1 << h); a++) {
            for (int b = 0; b < (1 << h); b++) {
                if (a & b)
                    continue;
        
                int ab = a | b, zeroRow = 0, ok = 1;
                for (int bit = 0; ok && bit < h; bit++) {
                    if (ab & (1 << bit)) {
                        ok &= zeroRow % 2 == 0;
                        zeroRow = 0;
                    } else {
                        zeroRow++;
                    }
                }
                ok &= zeroRow % 2 == 0;
                
                if (ok)
                    graph[h][a].push_back(b);
            }
        }
    }

    return graph;
}

bool solve() {
    int h, w;
    if (!(cin >> h >> w))
        return 0;

    if (h > w)
        swap(h, w);

    static vector<vector<vector<int>>> graph = prepare();

    vector<vector<long long>> ways(w + 1, vector<long long>(1 << h));
    ways[0][0] = 1;
    for (int len = 0; len < w; len++)
        for (int mask = 0; mask < (1 << h); mask++)
            for (int nextMask : graph[h][mask])
                ways[len + 1][nextMask] += ways[len][mask];

    cout << ways[w][0] << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}