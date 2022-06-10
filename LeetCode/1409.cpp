class Solution {
public:
    vector<int> processQueries(vector<int> &queries, int n) {
        vector<int> p(n);
        iota(p.begin(), p.end(), 1);
        
        vector<int> res(queries.size());
        for (int i = 0; i < queries.size(); i++) {
            res[i] = find(p.begin(), p.end(), queries[i]) - p.begin();
            rotate(p.begin(), p.begin() + res[i], p.begin() + res[i] + 1);
        }
        
        return res;
    }
};