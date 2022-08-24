class Solution {
    int getSum(vector<int> &p, int l, int r) {
        if (l > r)
            return 0;
        return p[r] - (l ? p[l - 1] : 0);
    }
    
    int rec(vector<int> &p, int from, int jump, vector<vector<int>> &memo) {
        if (from >= p.size())
            return 0;
        
        if (jump > p.size())
            jump = p.size();
        
        int &res = memo[from][jump];
        if (res != -1)
            return res;
        
        res = 0;
        
        for (int count = 1; count <= 2 * jump && from + count <= p.size(); count++) {
            int profit = getSum(p, from, from + count - 1);
            int futureProfit = getSum(p, from + count, p.size() - 1) - rec(p, from + count, max(jump, count), memo);
            res = max(res, profit + futureProfit);
        }
        
        return res;
    }
    
public:
    int stoneGameII(vector<int> &p) {
        partial_sum(p.begin(), p.end(), p.begin());
        vector<vector<int>> memo(p.size(), vector<int>(p.size() + 1, -1));
        return rec(p, 0, 1, memo);
    }
};