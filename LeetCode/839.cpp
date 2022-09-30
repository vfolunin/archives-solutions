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
    bool areSimilar(string &a, string &b) {
        int l = 0;
        while (l < a.size() && a[l] == b[l])
            l++;
        
        if (l == a.size())
            return 1;
        
        int r = a.size() - 1;
        while (a[r] == b[r])
            r--;
        
        if (l == r)
            return 0;
        
        string s = a;
        swap(s[l], s[r]);
        return s == b;
    }
    
public:
    int numSimilarGroups(vector<string> &a) {
        DSU dsu(a.size());
        
        for (int i = 0; i < a.size(); i++)
            for (int j = i + 1; j < a.size(); j++)
                if (areSimilar(a[i], a[j]))
                    dsu.merge(i, j);
        
        return dsu.cc;
    }
};