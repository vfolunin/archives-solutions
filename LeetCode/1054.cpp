class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int> &a) {
        unordered_map<int, int> count;
        for (int value : a)
            count[value]++;
        
        set<pair<int, int>> pairs;
        for (auto &[value, count] : count)
            pairs.insert({ count, value });
        
        vector<int> res(a.size());
        
        for (int i = 0; i < res.size(); i++) {
            auto it = prev(pairs.end());
            if (i && res[i - 1] == it->second)
                it--;
            
            auto [count, value] = *it;
            res[i] = value;
            pairs.erase(it);
            if (count > 1)
                pairs.insert({ count - 1, value });
        }
        
        return res;
    }
};