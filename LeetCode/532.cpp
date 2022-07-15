class Solution {
public:
    int findPairs(vector<int> &a, int diff) {
        int res = 0;
        
        if (diff) {
            unordered_set<int> values(a.begin(), a.end());
            for (int value : values)
                res += values.count(value + diff);
        } else {
            unordered_map<int, int> count;
            for (int value : a)
                count[value]++;
            
            for (auto &[value, count] : count)
                res += count > 1;
        }
        
        return res;
    }
};