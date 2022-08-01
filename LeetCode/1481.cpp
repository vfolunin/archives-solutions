class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int> &a, int k) {
        unordered_map<int, int> count;
        for (int value : a)
            count[value]++;
        
        vector<pair<int, int>> pairs(count.begin(), count.end());
        sort(pairs.begin(), pairs.end(), [](auto &a, auto &b) {
            return a.second < b.second;
        });
        
        for (int i = 0; i < pairs.size(); i++) {
            if (k >= pairs[i].second)
                k -= pairs[i].second;
            else
                return pairs.size() - i;
        }
        
        return 0;
    }
};