struct DSU {
    vector<int> parent;
    int ccCount;

    DSU(int vertexCount, int ccCount) : ccCount(ccCount) {
        for (int v = 0; v < vertexCount; v++)
            parent.push_back(v);
    }

    int findRoot(int v) {
        return parent[v] == v ? v : parent[v] = findRoot(parent[v]);
    }

    bool areConnected(int a, int b) {
        return findRoot(a) == findRoot(b);
    }

    void connect(int a, int b) {
        int rootA = findRoot(a);
        int rootB = findRoot(b);
        if (rootA == rootB)
            return;
        if (rand() % 2)
            parent[rootA] = rootB;
        else
            parent[rootB] = rootA;
        ccCount--;
    }
};

int ones(int n) {
    int res = 0;
    while (n) {
        res++;
        n &= n - 1;
    }
    return res;
}

class Solution {
public:
    int evenSumSubgraphs(vector<int> &values, vector<vector<int>> &edges) {
        int res = 0;
        for (int mask = 0; mask < (1 << values.size()); mask++) {
            int sum = 0;
            for (int v = 0; v < values.size(); v++)
                if (mask & (1 << v))
                    sum += values[v];
            if (sum % 2)
                continue;
            
            DSU dsu(values.size(), ones(mask));
            for (vector<int> &edge : edges) {
                int a = edge[0], b = edge[1];
                if ((mask & (1 << a)) && (mask & (1 << b)) && !dsu.areConnected(a, b))
                    dsu.connect(a, b);
            }
            if (dsu.ccCount == 1)
                cout << mask << endl;
            res += dsu.ccCount == 1;
        }
        return res;
    }
};