class Solution {
public:
    int findMaxLength(vector<int> &a) {
        unordered_map<int, int> seen = { { 0, -1 } };
        int balance = 0, res = 0;        
        
        for (int i = 0; i < a.size(); i++) {
            balance += a[i] ? 1 : -1;
            if (seen.count(balance))
                res = max(res, i - seen[balance]);
            else
                seen[balance] = i;
        }
        
        return res;
    }
};