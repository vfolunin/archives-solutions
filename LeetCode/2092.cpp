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
    vector<int> findAllPeople(int vertexCount, vector<vector<int>> &edges, int firstPerson) {
        DSU dsu(vertexCount);
        dsu.merge(0, firstPerson);
        
        sort(edges.begin(), edges.end(), [](auto &a, auto &b) {
            return a[2] < b[2];
        });
        
        for (int l = 0, r = 0; l < edges.size(); l = r) {
            unordered_set<int> vertices;
            for ( ; r < edges.size() && edges[l][2] == edges[r][2]; r++) {
                dsu.merge(edges[r][0], edges[r][1]);
                vertices.insert(edges[r][0]);
                vertices.insert(edges[r][1]);
            }
            for (int v : vertices)
                if (!dsu.connected(0, v))
                    dsu.id[v] = v;
        }
        
        vector<int> res;
        for (int v = 0; v < vertexCount; v++)
            if (dsu.connected(0, v))
                res.push_back(v);
        return res;
    }
};