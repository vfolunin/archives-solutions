class Solution {
    bool can(long long k, vector<int> &need, vector<int> &have, vector<int> &price, int money) {
        long long cost = 0;
        for (int i = 0; i < need.size(); i++)
            cost += max(0LL, need[i] * k - have[i]) * price[i];
        return cost <= money;
    }
    
public:
    int maxNumberOfAlloys(int w, int h, int money, vector<vector<int>> &need, vector<int> &have, vector<int> &price) {
        int res = 0;
        
        for (vector<int> &need : need) {
            int l = 0, r = 1e9;            
            while (l + 1 < r) {
                int m = l + (r - l) / 2;
                if (can(m, need, have, price, money))
                    l = m;
                else
                    r = m;
            }            
            res = max(res, l);
        }
        
        return res;
    }
};