class Solution {
public:
    int distinctAverages(vector<int> &a) {
        multiset<int> values(a.begin(), a.end());
        unordered_set<int> sums;
        
        while (!values.empty()) {
            sums.insert(*values.begin() + *prev(values.end()));
            values.erase(values.begin());
            values.erase(prev(values.end()));
        }
        
        return sums.size();
    }
};