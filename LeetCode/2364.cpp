class Solution {
public:
    long long countBadPairs(vector<int> &a) {
        unordered_map<int, long long> count;
        for (int i = 0; i < a.size(); i++)
            count[a[i] - i]++;
        
        long long res = a.size() * (a.size() - 1) / 2;
        
        for (auto &[value, count] : count)
            res -= count * (count - 1) / 2;
        
        return res;
    }
};