class Solution {
public:
    vector<int> findOriginalArray(vector<int> &a) {
        multiset<int> values(a.begin(), a.end());
        vector<int> res;
        
        while (!values.empty()) {
            res.push_back(*values.begin());
            values.erase(values.begin());
            if (auto it = values.find(2 * res.back()); it != values.end())
                values.erase(it);
            else
                return {};
        }
        
        return res;
    }
};