class Solution {
    int ones(int n) {
        int res = 0;
        while (n) {
            res++;
            n &= n - 1;
        }
        return res;
    }

public:
    int minActivationCost(vector<vector<int>> &edges, vector<int> &values) {
        for (int &value : values)
            value = ones(value) % 2;

        int res = 2.1e9;
        vector<multiset<int>> weights(values.size());
        for (vector<int> &edge : edges) {
            int a = edge[0], b = edge[1], weight = edge[2];
            if (values[a] == values[b]) {
                res = min(res, weight);
            } else {
                if (values[a])
                    swap(a, b);
                weights[a].insert(weight);
            }
        }
        
        for (int v = 0; v < values.size(); v++)
            if (!values[v] && weights[v].size() >= 2)
                res = min(res, *weights[v].begin() + *next(weights[v].begin()));

        return res < 2.1e9 ? res : -1;
    }
};