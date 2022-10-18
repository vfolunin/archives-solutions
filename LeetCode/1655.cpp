class Solution {
    int rec(int i, int mask, vector<vector<int>> &can, vector<vector<int>> &memo) {
        int &res = memo[i][mask];
        if (res != -1)
            return res;
        
        if (!i)
            return res = !mask;
        
        for (int submask : can[i - 1])
            if ((mask & submask) == submask && rec(i - 1, mask ^ submask, can, memo))
                return res = 1;
        
        return res = 0;
    }
    
public:
    bool canDistribute(vector<int> &a, vector<int> &need) {
        unordered_map<int, int> count;
        for (int value : a)
            count[value]++;
        
        vector<int> have;
        for (auto &[value, count] : count)
            have.push_back(count);
        
        vector<vector<int>> can(have.size());
        for (int mask = 0; mask < (1 << need.size()); mask++) {
            int totalNeed = 0;
            for (int bit = 0; bit < need.size(); bit++)
                if (mask & (1 << bit))
                    totalNeed += need[bit];
            
            for (int i = 0; i < have.size(); i++)
                if (totalNeed <= have[i])
                    can[i].push_back(mask);
        }
        
        vector<vector<int>> memo(have.size() + 1, vector<int>(1 << need.size(), -1));
        return rec(have.size(), (1 << need.size()) - 1, can, memo);
    }
};