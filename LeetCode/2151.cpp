class Solution {
    int ones(int n) {
        int res = 0;
        while (n) {
            res++;
            n &= n - 1;
        }
        return res;
    }
    
public:
    int maximumGood(vector<vector<int>> &statements) {
        int res = 0;
        
        for (int mask = 0; mask < (1 << statements.size()); mask++) {
            bool ok = 1;
            for (int i = 0; ok && i < statements.size(); i++)
                if (mask & (1 << i))
                    for (int j = 0; ok && j < statements.size(); j++)
                        if (statements[i][j] != 2)
                            ok &= (bool)(mask & (1 << j)) == statements[i][j];
            
            if (ok)
               res = max(res, ones(mask));
        }
        
        return res;
    }
};