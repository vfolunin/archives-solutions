struct SegmentTree {
    int size;
    vector<int> t;

    void build(int v, int vl, int vr, vector<int> &path, string &s) {
        if (vl == vr) {
            t[v] = 1 << (s[path[vl]] - 'a');
            return;
        }
        int vm = vl + (vr - vl) / 2;
        build(2 * v + 1, vl, vm, path, s);
        build(2 * v + 2, vm + 1, vr, path, s);
        t[v] = t[2 * v + 1] ^ t[2 * v + 2];
    }

    int query(int v, int vl, int vr, int l, int r) {
        if (vr < l || r < vl)
            return 0;
        if (l <= vl && vr <= r)
            return t[v];
        int vm = vl + (vr - vl) / 2;
        int ql = query(2 * v + 1, vl, vm, l, r);
        int qr = query(2 * v + 2, vm + 1, vr, l, r);
        return ql ^ qr;
    }

    void modify(int v, int vl, int vr, int index, char oldChar, char newChar) {
        if (vr < index || index < vl)
            return;
        if (vl == vr) {
            t[v] ^= (1 << (oldChar - 'a')) ^ (1 << (newChar - 'a'));
            return;
        }
        int vm = vl + (vr - vl) / 2;
        modify(2 * v + 1, vl, vm, index, oldChar, newChar);
        modify(2 * v + 2, vm + 1, vr, index, oldChar, newChar);
        t[v] = t[2 * v + 1] ^ t[2 * v + 2];
    }

    SegmentTree(vector<int> &path, string &s) : size(path.size()), t(4 * size) {
        build(0, 0, size - 1, path, s);
    }

    int getMask(int l, int r) {
        return query(0, 0, size - 1, l, r);
    }

    void setChar(int index, char oldChar, char newChar) {
        if (oldChar != newChar)
            modify(0, 0, size - 1, index, oldChar, newChar);
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

    void prepare(int root, string &s) {
        dfs1(root, -1);
        dfs2(root, 0);
        for (vector<int> &path : paths)
            segmentTrees.push_back(SegmentTree(path, s));
    }

    bool isPalindrome(int a, int b) {
        int mask = 0;

        while (pathOf[a] != pathOf[b]) {
            if (depth[paths[pathOf[a]][0]] > depth[paths[pathOf[b]][0]])
                swap(a, b);
            mask ^= segmentTrees[pathOf[b]].getMask(0, posOf[b]);
            b = parent[paths[pathOf[b]][0]];
        }

        if (depth[a] > depth[b])
            swap(a, b);
        mask ^= segmentTrees[pathOf[a]].getMask(posOf[a], posOf[b]);

        return !(mask & (mask - 1));
    }

    void setChar(int v, char oldChar, char newChar) {
        segmentTrees[pathOf[v]].setChar(posOf[v], oldChar, newChar);
    }
};

class Solution {
public:
    vector<bool> palindromePath(int vertexCount, vector<vector<int>> &edges, string &s, vector<string> &queries) {
        HeavyLightDecomposition heavyLightDecomposition(vertexCount);
        for (vector<int> &edge : edges)
            heavyLightDecomposition.addEdge(edge[0], edge[1]);
        heavyLightDecomposition.prepare(0, s);

        vector<bool> res;
        for (string &query : queries) {
            stringstream ss(query);
            string type;
            ss >> type;

            if (type == "query") {
                int a, b;
                ss >> a >> b;

                res.push_back(heavyLightDecomposition.isPalindrome(a, b));
            } else {
                int v;
                char c;
                ss >> v >> c;

                heavyLightDecomposition.setChar(v, s[v], c);
                s[v] = c;
            }
        }
        return res;
    }
};