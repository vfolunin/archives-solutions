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

class Solution {
    int kruskal(int vertexCount, vector<vector<int>> &edges, vector<int> &order) {
        DSU dsu(vertexCount);
        
        int mstWeight = 0;
        for (int index : order) {
            if (!dsu.connected(edges[index][0], edges[index][1])) {
                dsu.merge(edges[index][0], edges[index][1]);
                mstWeight += edges[index][2];
            }
        }
        
        return dsu.cc == 1 ? mstWeight : (int)1e9;
    }
    
    bool isCritical(int vertexCount, vector<vector<int>> &edges, vector<int> order, int index, int mstWeight) {
        order.erase(find(order.begin(), order.end(), index));
        return kruskal(vertexCount, edges, order) > mstWeight;
    }
    
    bool isPseudoCritical(int vertexCount, vector<vector<int>> &edges, vector<int> order, int index, int mstWeight) {
        order.erase(find(order.begin(), order.end(), index));
        order.insert(order.begin(), index);
        return kruskal(vertexCount, edges, order) == mstWeight;
    }
    
public:
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int vertexCount, vector<vector<int>> &edges) {
        vector<int> order(edges.size());
        iota(order.begin(), order.end(), 0);
        sort(order.begin(), order.end(), [&](auto &a, auto &b) {
            return edges[a][2] < edges[b][2];
        });
        
        int mstWeight = kruskal(vertexCount, edges, order);
        vector<vector<int>> res(2);
        
        for (int i = 0; i < edges.size(); i++) {
            if (isCritical(vertexCount, edges, order, i, mstWeight))
                res[0].push_back(i);
            else if (isPseudoCritical(vertexCount, edges, order, i, mstWeight))
                res[1].push_back(i);
        }
        
        return res;
    }
};