class Solution {
public:
    vector<int> topKFrequent(vector<int> &a, int k) {
        unordered_map<int, int> count;
        for (int value : a) 
            count[value]++;
        
        vector<pair<int, int>> pairs(count.begin(), count.end());
        partial_sort(pairs.begin(), pairs.begin() + k, pairs.end(),
                     [](auto &a, auto &b) { return a.second > b.second; });
            
        vector<int> res(k);
        for (int i = 0; i < k; i++) 
            res[i] = pairs[i].first;
        return res;
    }
};