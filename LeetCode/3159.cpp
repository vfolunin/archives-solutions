class Solution {
public:
    vector<int> occurrencesOfElement(vector<int> &a, vector<int> &queries, int value) {
        vector<int> pos;
        for (int i = 0; i < a.size(); i++)
            if (a[i] == value)
                pos.push_back(i);
        
        vector<int> res(queries.size());
        for (int i = 0; i < res.size(); i++)
            res[i] = queries[i] <= pos.size() ? pos[queries[i] - 1] : -1;
        return res;
    }
};