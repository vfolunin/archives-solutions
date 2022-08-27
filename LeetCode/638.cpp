class Solution {
    int rec(vector<int> &price, vector<vector<int>> &specials, vector<int> &need, map<vector<int>, int> &memo) {
        if (memo.count(need))
            return memo[need];
        int &res = memo[need];
        
        res = 1e9;
        
        if (count(need.begin(), need.end(), 0) == need.size())
            return res = 0;
        
        for (vector<int> &special : specials) {
            bool ok = 1;
            for (int i = 0; i < need.size() && ok; i++)
                ok &= need[i] >= special[i];
            
            if (ok) {
                for (int i = 0; i < need.size() && ok; i++)
                    need[i] -= special[i];
                res = min(res, rec(price, specials, need, memo) + special.back());
                for (int i = 0; i < need.size() && ok; i++)
                    need[i] += special[i];
            }
        }
        
        for (int i = 0; i < need.size(); i++) {
            if (need[i]) {
                int count = need[i];
                need[i] = 0;
                res = min(res, rec(price, specials, need, memo) + count * price[i]);
                need[i] = count;
            }
        }
        
        
        
        return res;
    }
    
public:
    int shoppingOffers(vector<int> &price, vector<vector<int>> &specials, vector<int> &need) {
        map<vector<int>, int> memo;
        return rec(price, specials, need, memo);
    }
};