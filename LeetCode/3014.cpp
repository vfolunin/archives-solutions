class Solution {
public:
    int minimumPushes(string &s) {
        unordered_map<char, int> count;
        for (char c : s)
            count[c]++;
        
        multiset<int> counts;
        for (auto &[c, count] : count)
            counts.insert(count);
        
        int res = 0;
        for (int cost = 1; !counts.empty(); cost++) {
            for (int i = 0; i < 8 && !counts.empty(); i++) {
                res += *prev(counts.end()) * cost;
                counts.erase(prev(counts.end()));
            }
        }
        return res;
    }
};