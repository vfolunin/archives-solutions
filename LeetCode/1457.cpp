class Solution {
    int rec(TreeNode *n, vector<int> &count) {
        count[n->val]++;
        
        if (!n->left && !n->right) {
            int odd = 0;
            for (int value : count)
                odd += value % 2;
            
            count[n->val]--;
            return odd <= 1;
        }
        
        int res = 0;
        if (n->left)
            res += rec(n->left, count);
        if (n->right)
            res += rec(n->right, count);
        
        count[n->val]--;
        return res;
    }
    
public:
    int pseudoPalindromicPaths(TreeNode *root) {
        vector<int> count(10);
        return rec(root, count);
    }
};