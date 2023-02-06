class Solution {
public:
    vector<int> getModifiedArray(int size, vector<vector<int>> &queries) {
        vector<int> p(size);
        for (vector<int> &query : queries) {
            p[query[0]] += query[2];
            if (query[1] + 1 < size)
                p[query[1] + 1] -= query[2];
        }
        partial_sum(p.begin(), p.end(), p.begin());
        return p;
    }
};