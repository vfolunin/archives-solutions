struct DSU {
    vector<int> id;

    DSU(int n) {
        for (int v = 0; v < n; v++)
            id.push_back(v);
    }

    int find(int i) {
        return id[i] == i ? i : id[i] = find(id[i]);
    }

    bool connected(int i, int j) {
        return find(i) == find(j);
    }

    void merge(int i, int j) {
        int ri = find(i), rj = find(j);
        if (ri == rj)
            return;
        if (rand() % 2)
            id[ri] = rj;
        else
            id[rj] = ri;
    }
};

struct Edge {
    int a, b, w;
    
    bool operator < (const Edge &that) const {
        return w < that.w;
    }
};

class Solution {
public:
    int minCostToSupplyWater(int vertexCount, vector<int> &cost, vector<vector<int>> &pipes) {
        vertexCount++;

        vector<Edge> edges;
        for (int v = 1; v < vertexCount; v++)
            edges.push_back({ 0, v, cost[v - 1] });
        for (vector<int> &pipe : pipes)
            edges.push_back({ pipe[0], pipe[1], pipe[2] });
        sort(edges.begin(), edges.end());

        DSU dsu(vertexCount);
        int mstWeight = 0;
        for (auto &[a, b, w] : edges) {
            if (!dsu.connected(a, b)) {
                dsu.merge(a, b);
                mstWeight += w;
            }
        }
        return mstWeight;
    }
};