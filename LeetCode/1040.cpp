class Solution {
    int minMoves(vector<int> &a) {
        int res = 2e9;
        
        for (int l = 0, r = 0; r < a.size(); l++) {
            while (r < a.size() && a[l] + a.size() > a[r])
                r++;
            
            int ops = a.size() - (r - l);
            if (a[r - 1] - a[l] + 1 == a.size() - 1)
                ops++;
            
            res = min(res, ops);
        }
        
        return res;
    }
    
    int maxMoves(vector<int> &a) {
        return max(a[a.size() - 1] - a[1] + 1, a[a.size() - 2] - a[0] + 1) - (a.size() - 1);
    }
    
public:
    vector<int> numMovesStonesII(vector<int> &a) {
        sort(a.begin(), a.end());
        return { minMoves(a), maxMoves(a) };
    }
};