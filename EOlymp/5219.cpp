#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct SegmentTree {
    int size;
    vector<int> t;

    int query(int v, int vl, int vr, int l, int r) {
        if (vr < l || r < vl)
            return -1e9;
        if (l <= vl && vr <= r)
            return t[v];
        int vm = vl + (vr - vl) / 2;
        int ql = query(2 * v + 1, vl, vm, l, r);
        int qr = query(2 * v + 2, vm + 1, vr, l, r);
        return max(ql, qr);
    }

    void modify(int v, int vl, int vr, int index, int value) {
        if (vr < index || index < vl)
            return;
        if (vl == vr) {
            t[v] += value;
            return;
        }
        int vm = vl + (vr - vl) / 2;
        modify(2 * v + 1, vl, vm, index, value);
        modify(2 * v + 2, vm + 1, vr, index, value);
        t[v] = max(t[2 * v + 1], t[2 * v + 2]);
    }

    SegmentTree(int size) : size(size), t(4 * size) {}

    int getMax(int l, int r) {
        return query(0, 0, size - 1, l, r);
    }

    void addValue(int index, int value) {
        modify(0, 0, size - 1, index, value);
    }
};

struct HeavyLightDecomposition {
    vector<vector<int>> graph, paths;
    vector<int> parent, depth, subtreeSize, pathOf, posOf;
    vector<SegmentTree> segmentTrees;

    HeavyLightDecomposition(int vertexCount) :
        graph(vertexCount), parent(vertexCount), depth(vertexCount),
        subtreeSize(vertexCount), pathOf(vertexCount), posOf(vertexCount) {}

    void addEdge(int a, int b) {
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    int dfs1(int v, int p) {
        parent[v] = p;
        depth[v] = parent[v] != -1 ? depth[parent[v]] + 1 : 0;
        subtreeSize[v] = 1;
        for (int to : graph[v])
            if (to != parent[v])
                subtreeSize[v] += dfs1(to, v);
        return subtreeSize[v];
    }

    void dfs2(int v, int pathIndex) {
        if (paths.size() == pathIndex)
            paths.emplace_back();
        paths[pathIndex].push_back(v);

        pathOf[v] = pathIndex;
        posOf[v] = paths[pathIndex].size() - 1;

        int maxTo = -1;
        for (int to : graph[v])
            if (to != parent[v] && (maxTo == -1 || subtreeSize[maxTo] < subtreeSize[to]))
                maxTo = to;

        for (int to : graph[v])
            if (to != parent[v])
                dfs2(to, to == maxTo ? pathIndex : paths.size());
    }

    void prepare(int root) {
        dfs1(root, -1);
        dfs2(root, 0);
        for (vector<int> &path : paths)
            segmentTrees.push_back(SegmentTree(path.size()));
    }

    int getMax(int a, int b) {
        int res = -1e9;

        while (pathOf[a] != pathOf[b]) {
            if (depth[paths[pathOf[a]][0]] > depth[paths[pathOf[b]][0]])
                swap(a, b);
            res = max(res, segmentTrees[pathOf[b]].getMax(0, posOf[b]));
            b = parent[paths[pathOf[b]][0]];
        }

        if (depth[a] > depth[b])
            swap(a, b);
        res = max(res, segmentTrees[pathOf[a]].getMax(posOf[a], posOf[b]));

        return res;
    }

    void addValue(int v, int value) {
        segmentTrees[pathOf[v]].addValue(posOf[v], value);
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int vertexCount;
    cin >> vertexCount;

    HeavyLightDecomposition heavyLightDecomposition(vertexCount);
    for (int i = 0; i < vertexCount - 1; i++) {
        int a, b;
        cin >> a >> b;

        heavyLightDecomposition.addEdge(a - 1, b - 1);
    }

    heavyLightDecomposition.prepare(0);

    int queryCount;
    cin >> queryCount;

    for (int i = 0; i < queryCount; i++) {
        char type;
        int a, b;
        cin >> type >> a >> b;

        if (type == 'G')
            cout << heavyLightDecomposition.getMax(a - 1, b - 1) << "\n";
        else
            heavyLightDecomposition.addValue(a - 1, b);
    }
}