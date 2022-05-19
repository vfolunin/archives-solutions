class Solution {
public:
    int numTrees(int n) {
        static vector<int> memo(20);
        int &res = memo[n];
        if (res)
            return res;
        
        if (n <= 1)
            return res = 1;
        
        for (int l = 0, r = n - 1; l < n; l++, r--)
            res += numTrees(l) * numTrees(r);
        return res;
    }
};