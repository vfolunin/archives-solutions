struct DSU {
    vector<int> id, maxValue, maxCount;

    DSU(vector<int> &values) {
        for (int v = 0; v < values.size(); v++) {
            id.push_back(v);
            maxValue.push_back(values[v]);
            maxCount.push_back(1);
        }
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
            swap(ri, rj);
        
        if (maxValue[rj] < maxValue[ri]) {
            maxValue[rj] = maxValue[ri];
            maxCount[rj] = maxCount[ri];
        } else if (maxValue[rj] == maxValue[ri]) {
            maxCount[rj] += maxCount[ri];
        }
        
        id[ri] = rj;
    }
};

class Solution {
public:
    int numberOfGoodPaths(vector<int> &values, vector<vector<int>> &edges) {
        vector<int> order(values.size());
        iota(order.begin(), order.end(), 0);
        sort(order.begin(), order.end(), [&](int a, int b) {
            return values[a] < values[b];
        });
        
        vector<vector<int>> graph(values.size());
        for (vector<int> &edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        
        DSU dsu(values);
        vector<int> added(values.size());
        int res = values.size();
        
        for (int l = 0, r = 0; l < order.size(); ) {
            for ( ; r < order.size() && values[order[l]] == values[order[r]]; r++) {
                for (int to : graph[order[r]])
                    if (added[to])
                        dsu.merge(order[r], to);
                added[order[r]] = 1;
            }
            
            unordered_set<int> roots;
            for ( ; l < r; l++)
                roots.insert(dsu.find(order[l]));
            
            for (int root : roots) {
                int count = dsu.maxCount[root];
                res += count * (count - 1) / 2;
            }
        }
        
        return res;
    }
};