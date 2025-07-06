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

class Solution {
public:
    vector<int> processQueries(int vertexCount, vector<vector<int>> &edges, vector<vector<int>> &queries) {
        DSU dsu(vertexCount);
        for (vector<int> &edge : edges)
            dsu.merge(edge[0] - 1, edge[1] - 1);

        vector<set<int>> values(vertexCount);
        for (int v = 0; v < vertexCount; v++)
            values[dsu.find(v)].insert(v);
        
        vector<int> res;
        for (vector<int> &query : queries) {
            int type = query[0], v = query[1] - 1;
            set<int> &online = values[dsu.find(v)];

            if (type == 1) {
                if (online.count(v))
                    res.push_back(v + 1);
                else if (!online.empty())
                    res.push_back(*online.begin() + 1);
                else
                    res.push_back(-1);
            } else {
                online.erase(v);
            }
        }
        return res;
    }
};