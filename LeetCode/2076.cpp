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
    vector<bool> friendRequests(int n, vector<vector<int>> &restrictions, vector<vector<int>> &requests) {
        DSU dsu(n);
        vector<bool> res(requests.size(), 1);
        
        for (int i = 0; i < requests.size(); i++) {
            int ra = dsu.find(requests[i][0]), rb = dsu.find(requests[i][1]);
            
            for (vector<int> &restriction : restrictions) {
                int rc = dsu.find(restriction[0]), rd = dsu.find(restriction[1]);
                if (ra == rc && rb == rd || ra == rd && rb == rc) {
                    res[i] = 0;
                    break;
                }
            }
            
            if (res[i])
                dsu.merge(ra, rb);
        }
        
        return res;
    }
};