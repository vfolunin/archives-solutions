class Solution {
public:
    int findMinMoves(vector<int> &a) {
        int sum = 0;
        for (int value : a)
            sum += value;
        
        if (sum % a.size())
            return -1;
        
        int target = sum / a.size(), delta = 0, res = 0;
        for (int value : a) {
            delta += value - target;
            res = max({ res, value - target, abs(delta) });
        }
        return res;
    }
};