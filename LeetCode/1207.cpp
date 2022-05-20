class Solution {
public:
    bool uniqueOccurrences(vector<int> &a) {
        unordered_map<int, int> count;
        for (int value : a)
            count[value]++;
        
        unordered_set<int> res;
        for (auto &[value, count] : count)
            res.insert(count);
        
        return res.size() == count.size();
    }
};