struct DSU {
    vector<int> id;

    DSU() : id(26) {
        iota(id.begin(), id.end(), 0);
    }

    int find(int i) {
        return id[i] == i ? i : id[i] = find(id[i]);
    }

    void merge(int i, int j) {
        int ri = find(i), rj = find(j);
        if (ri > rj)
            swap(ri, rj);
        id[rj] = ri;
    }
};

class Solution {
public:
    string smallestEquivalentString(string &a, string &b, string &s) {
        DSU dsu;
        for (int i = 0; i < a.size(); i++)
            dsu.merge(a[i] - 'a', b[i] - 'a');
        
        for (char &c : s)
            c = 'a' + dsu.find(c - 'a');
        return s;
    }
};