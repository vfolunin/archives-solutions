struct Compressor {
    unordered_map<string, int> ids;

    int getId(string &word) {
        if (!ids.count(word))
            ids[word] = ids.size();
        return ids[word];
    }
};

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
    bool areSentencesSimilarTwo(vector<string> &a, vector<string> &b, vector<vector<string>> &edges) {
        if (a.size() != b.size())
            return 0;
            
        Compressor compressor;
        DSU dsu(5000);

        for (vector<string> &edge : edges)
            dsu.merge(compressor.getId(edge[0]), compressor.getId(edge[1]));
        
        for (int i = 0; i < a.size(); i++)
            if (!dsu.connected(compressor.getId(a[i]), compressor.getId(b[i])))
                return 0;
        return 1;
    }
};