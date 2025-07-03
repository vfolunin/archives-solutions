struct DSU {
    vector<int> id;
    int cc;

    DSU(int n) {
        for (int v = 0; v < n; v++)
            id.push_back(v);
        cc = n;
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
        cc--;
    }
};

struct Edge {
    int a, b, weight;
    bool inMst = 0;

    bool operator < (const Edge &that) const {
        if (inMst != that.inMst)
            return inMst;
        return weight > that.weight;
    }
};

class Solution {
public:
    int maxStability(int vertexCount, vector<vector<int>> &edgeVector, int limit) {
        vector<Edge> edges;
        for (vector<int> &edge : edgeVector)
            edges.emplace_back(edge[0], edge[1], edge[2], edge[3]);
        sort(edges.begin(), edges.end());

        DSU dsu(vertexCount);
        vector<pair<int, bool>> mstEdges;
        for (auto &[a, b, weight, inMst] : edges) {
            if (!dsu.connected(a, b)) {
                dsu.merge(a, b);
                mstEdges.emplace_back(weight, inMst);
            } else if (inMst) {
                return -1;
            }
        }
        if (dsu.cc != 1)
            return -1;

        sort(mstEdges.begin(), mstEdges.end());
        int res = 1e9;
        for (auto &[weight, inMst] : mstEdges) {
            if (!inMst && limit) {
                weight *= 2;
                limit--;
            }
            res = min(res, weight);
        }
        return res;
    }
};