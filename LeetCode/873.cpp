class Solution {
public:
    int lenLongestFibSubseq(vector<int> &a) {
        map<int, int> indexOf;
        for (int i = 0; i < a.size(); i++)
            indexOf[a[i]] = i;
        
        vector<vector<int>> res(a.size(), vector<int>(a.size()));
        int maxRes = 0;
        
        for (int i = 0; i < a.size(); i++) {
            for (int pi = 0; pi < i; pi++) {
                res[pi][i] = 2;
                if (indexOf.count(a[i] - a[pi]))
                    res[pi][i] = max(res[pi][i], res[indexOf[a[i] - a[pi]]][pi] + 1);                
                maxRes = max(maxRes, res[pi][i]);
            }
        }
        
        return maxRes > 2 ? maxRes : 0;
    }
};