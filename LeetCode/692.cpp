class Solution {
public:
    vector<string> topKFrequent(vector<string> &words, int k) {
        unordered_map<string, int> count;
        for (string &word : words)
            count[word]++;
        
        vector<pair<string, int>> pairs(count.begin(), count.end());
        partial_sort(pairs.begin(), pairs.begin() + k, pairs.end(), [](auto &a,  auto &b) {
            if (a.second != b.second)
                return a.second > b.second;
            return a.first < b.first;
        });
        
        vector<string> res(k);
        for (int i = 0; i < res.size(); i++)
            res[i] = pairs[i].first;
        return res;
    }
};