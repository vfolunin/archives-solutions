class Solution {
    int rec(vector<int> &count, int mod, map<pair<vector<int>, int>, int> &memo) {
        if (memo.count({ count, mod }))
            return memo[{ count, mod }];
        int &res = memo[{ count, mod }];
        
        for (int group = 0; group < count.size(); group++) {
            if (!count[group])
                continue;
            
            count[group]--;
            res = max(res, !mod + rec(count, (mod + group) % count.size(), memo));
            count[group]++;
        }
        
        return res;
    }
    
public:
    int maxHappyGroups(int batchSize, vector<int> &groups) {
        vector<int> count(batchSize);
        int res = 0;
        
        for (int group : groups) {
            if (group % batchSize == 0) {
                res++;
            } else if (count[batchSize - group % batchSize]) {
                count[batchSize - group % batchSize]--;
                res++;
            } else {
                count[group % batchSize]++;
            }
        }
        
        map<pair<vector<int>, int>, int> memo;
        
        return res + rec(count, 0, memo);
    }
};