class Solution {
public:
    int countKDifference(vector<int> &a, int k) {
        unordered_map<int, int> seen;
        
        int res = 0;
        
        for (int value : a) {
            if (seen.count(value - k))
                res += seen[value - k];
            if (seen.count(value + k))
                res += seen[value + k];
            
            seen[value]++;
        }
        
        return res;
    }
};