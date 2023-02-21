class Solution {
public:
    vector<vector<int>> findRLEArray(vector<vector<int>> &a, vector<vector<int>> &b) {
        vector<vector<int>> res;

        for (int ai = 0, bi = 0; ai < a.size() && bi < b.size(); ) {
            int value = a[ai][0] * b[bi][0];
            int count = min(a[ai][1], b[bi][1]);

            if (res.empty() || res.back()[0] != value)
                res.push_back({ value, count });
            else
                res.back().back() += count;
            
            if (a[ai][1] > count)
                a[ai][1] -= count;
            else
                ai++;
            
            if (b[bi][1] > count)
                b[bi][1] -= count;
            else
                bi++;
        }

        return res;
    }
};