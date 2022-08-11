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
    bool equationsPossible(vector<string> &equations) {
        DSU dsu(26);
        
        for (string &equation : equations)
            if (equation[1] == '=')
                dsu.merge(equation[0] - 'a', equation[3] - 'a');
        
        for (string &equation : equations)
            if (equation[1] == '!' && dsu.connected(equation[0] - 'a', equation[3] - 'a'))
                return 0;
        return 1;
    }
};