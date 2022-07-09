class Solution {
    void rec(int size, int diff, int value, vector<int> &res) {
        if (!size) {
            res.push_back(value);
            return;
        }
        
        int digit = value % 10 - diff;
        if (0 <= digit)
            rec(size - 1, diff, value * 10 + digit, res);
        
        if (diff) {
            digit = value % 10 + diff;
            if (digit <= 9)
                rec(size - 1, diff, value * 10 + digit, res);
        }
    }
    
public:
    vector<int> numsSameConsecDiff(int size, int diff) {
        vector<int> res;
        for (int value = 1; value < 10; value++)
            rec(size - 1, diff, value, res);
        return res;
    }
};