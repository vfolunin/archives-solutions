class Solution {
public:
    vector<int> missingRolls(vector<int> &rolls, int mean, int n) {
        int sum = mean * (rolls.size() + n);
        for (int roll : rolls)
            sum -= roll;
        
        if (sum < n || sum > 6 * n)
            return {};
        
        vector<int> res(n, 1);
        sum -= n;
        
        for (int &roll : res) {
            int delta = min(sum, 5);
            roll += delta;
            sum -= delta;
        }
        
        return res;
    }
};