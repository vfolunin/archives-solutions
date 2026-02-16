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

    void build(int v, int vl, int vr, vector<int> &path, vector<int> &values) {
        if (vl == vr) {
            t[v] = values[path[vl]];
            return;
        }
        int vm = vl + (vr - vl) / 2;
        build(2 * v + 1, vl, vm, path, values);
        build(2 * v + 2, vm + 1, vr, path, values);
        t[v] = max(t[2 * v + 1], t[2 * v + 2]);
    }

    int query(int v, int vl, int vr, int l, int r) {
        if (l <= vl && vr <= r)
            return t[v];
        int vm = vl + (vr - vl) / 2;
        if (r <= vm)
            return query(2 * v + 1, vl, vm, l, r);
        if (vm + 1 <= l)
            return query(2 * v + 2, vm + 1, vr, l, r);
        int ql = query(2 * v + 1, vl, vm, l, r);
        int qr = query(2 * v + 2, vm + 1, vr, l, r);
        return max(ql, qr);
    }

    void modify(int v, int vl, int vr, int index, int value) {
        if (vl == vr) {
            t[v] = value;
            return;
        }
        int vm = vl + (vr - vl) / 2;
        if (index <= vm)
            modify(2 * v + 1, vl, vm, index, value);
        else
            modify(2 * v + 2, vm + 1, vr, index, value);
        t[v] = max(t[2 * v + 1], t[2 * v + 2]);
    }

    SegmentTree(vector<int> &path, vector<int> &values) : size(path.size()), t(4 * size) {
        build(0, 0, size - 1, path, values);
    }

    int getMax(int l, int r) {
        return query(0, 0, size - 1, l, r);
    }

    void setValue(int index, int value) {
        modify(0, 0, size - 1, index, value);
    }
};

struct HeavyLightDecomposition {
    vector<vector<int>> graph;
    vector<int> l, r, parent, subtreeSize;
    int timer = 0;
    vector<vector<int>> paths;
    vector<int> pathOf, posOf;
    vector<SegmentTree> segmentTrees;

    HeavyLightDecomposition(int vertexCount) :
        graph(vertexCount), l(vertexCount), r(vertexCount),
        parent(vertexCount), subtreeSize(vertexCount),
        pathOf(vertexCount), posOf(vertexCount) {}

    void addEdge(int a, int b) {
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    int dfs(int v, int p) {
        l[v] = timer++;
        parent[v] = p;
        subtreeSize[v] = 1;

        for (int to : graph[v])
            if (to != parent[v])
                subtreeSize[v] += dfs(to, v);

        r[v] = timer++;
        return subtreeSize[v];
    }

    bool isAncestor(int a, int b) {
        return l[a] <= l[b] && r[b] <= r[a];
    }

    void buildPath(int v, int pathIndex) {
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
                buildPath(to, to == maxTo ? pathIndex : paths.size());
    }

    void prepare(int root, vector<int> &values) {
        dfs(root, -1);
        buildPath(root, 0);
        for (vector<int> &path : paths)
            segmentTrees.push_back(SegmentTree(path, values));
    }

    int getMax(int a, int b) {
        int res = 0;

        for (; !isAncestor(paths[pathOf[a]][0], b); a = parent[paths[pathOf[a]][0]])
            res = max(res, segmentTrees[pathOf[a]].getMax(0, posOf[a]));
        for (; !isAncestor(paths[pathOf[b]][0], a); b = parent[paths[pathOf[b]][0]])
            res = max(res, segmentTrees[pathOf[b]].getMax(0, posOf[b]));

        if (posOf[a] > posOf[b])
            swap(a, b);
        return max(res, segmentTrees[pathOf[a]].getMax(posOf[a], posOf[b]));
    }

    void setValue(int v, int value) {
        segmentTrees[pathOf[v]].setValue(posOf[v], value);
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int vertexCount, queryCount;
    cin >> vertexCount >> queryCount;

    vector<int> values(vertexCount);
    for (int &value : values)
        cin >> value;

    HeavyLightDecomposition heavyLightDecomposition(vertexCount);
    for (int i = 0; i < vertexCount - 1; i++) {
        int a, b;
        cin >> a >> b;

        heavyLightDecomposition.addEdge(a - 1, b - 1);
    }

    heavyLightDecomposition.prepare(0, values);

    for (int i = 0; i < queryCount; i++) {
        int type, a, b;
        cin >> type >> a >> b;

        if (type == 1)
            heavyLightDecomposition.setValue(a - 1, b);
        else
            cout << heavyLightDecomposition.getMax(a - 1, b - 1) << " ";
    }
}