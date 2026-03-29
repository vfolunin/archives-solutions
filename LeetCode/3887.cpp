struct DSU {
    vector<int> parent, size, edgeXorSum;

    DSU(int vertexCount) {
        for (int v = 0; v < vertexCount; v++)
            parent.push_back(v);
        size.assign(vertexCount, 1);
        edgeXorSum.resize(vertexCount);
    }

    pair<int, int> findRoot(int v) {
        if (parent[v] == v)
            return { v, 0 };
        
        auto [root, rootEdgeXorSum] = findRoot(parent[v]);
        parent[v] = root;
        edgeXorSum[v] ^= rootEdgeXorSum;
        return { parent[v], edgeXorSum[v] };
    }

    int merge(int a, int b, int weight) {
        auto [aRoot, aEdgeXorSum] = findRoot(a);
        auto [bRoot, bEdgeXorSum] = findRoot(b);

        if (aRoot == bRoot)
            return !(aEdgeXorSum ^ bEdgeXorSum ^ weight);

        if (size[aRoot] < size[bRoot]) {
            parent[aRoot] = bRoot;
            size[bRoot] += size[aRoot];
            edgeXorSum[aRoot] = aEdgeXorSum ^ bEdgeXorSum ^ weight;
        } else {
            parent[bRoot] = aRoot;
            size[aRoot] += size[bRoot];
            edgeXorSum[bRoot] = aEdgeXorSum ^ bEdgeXorSum ^ weight;
        }
        return 1;
    }
};

class Solution {
public:
    int numberOfEdgesAdded(int vertexCount, vector<vector<int>> &edges) {
        DSU dsu(vertexCount);
        int res = 0;
        for (vector<int> &edge : edges)
            res += dsu.merge(edge[0], edge[1], edge[2]);
        return res;
    }
};