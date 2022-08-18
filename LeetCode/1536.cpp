class Solution {
public:
    int minSwaps(vector<vector<int>> &a) {
        int res = 0;
        
        for (int to = 0; to < a.size(); to++) {
            int from = -1;
            
            for (int i = to; i < a.size(); i++) {
                bool ok = true;
                
                for (int j = to + 1; ok && j < a.size(); j++)
                    ok &= !a[i][j];
                
                if (ok) {
                    from = i;
                    break;
                }
            }
            
            if (from == -1)
                return -1;
            
            res += from - to;
            rotate(a.begin() + to, a.begin() + from, a.begin() + from + 1);
        }
        
        return res;
    }
};