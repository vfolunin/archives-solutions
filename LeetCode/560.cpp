class Solution {
public:
    int subarraySum(vector<int> &a, int k) {
        unordered_map<int, int> seen = { { 0, 1 } };
        int sum = 0, res = 0;
        
        for (int value : a) {
            sum += value;
            if (seen.count(sum - k))
                res += seen[sum - k];
            seen[sum]++;
        }
        
        return res;
    }
};