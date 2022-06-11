class Solution {
public:
    vector<TreeNode *> allPossibleFBT(int n) {
        static vector<vector<TreeNode *>> memo(21);
        static vector<bool> ready(21);
        
        vector<TreeNode *> &res = memo[n];
        if (ready[n])
            return res;
        ready[n] = 1;
        
        if (n == 1)
            return res = { new TreeNode };
        
        for (int l = 1, r = n - 2; r; l++, r--)
            for (TreeNode *a : allPossibleFBT(l))
                for (TreeNode *b : allPossibleFBT(r))
                    res.push_back(new TreeNode(0, a, b));
        return res;
    }
};