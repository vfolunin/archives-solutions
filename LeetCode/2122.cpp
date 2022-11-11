class Solution {
    bool can(vector<int> &a, int k) {
        multiset<int> values(a.begin(), a.end());
        while (!values.empty()) {
            if (auto it = values.find(*values.begin() + 2 * k); it != values.end()) {
                values.erase(it);
                values.erase(values.begin());
            } else {
                return 0;
            }
        }
        return 1;
    }
                             
    vector<int> restore(vector<int> &a, int k) {
        multiset<int> values(a.begin(), a.end());
        vector<int> res;
        while (!values.empty()) {
            res.push_back(*values.begin() + k);
            values.erase(values.find(*values.begin() + 2 * k));
            values.erase(values.begin());
        }
        return res;
    }
    
public:
    vector<int> recoverArray(vector<int> &a) {
        sort(a.begin(), a.end());
        
        for (int i = 1; i < a.size(); i++)
            if (a[i] > a[0] && (a[i] - a[0]) % 2 == 0 && can(a, (a[i] - a[0]) / 2))
                return restore(a, (a[i] - a[0]) / 2);
        
        return {};
    }
};