class Solution {
    void rec(TreeNode *n, int value, int &sum) {
        if (!n)
            return;
        
        value = value * 2 + n->val;
        if (!n->left && !n->right)
            sum += value;
        
        rec(n->left, value, sum);
        rec(n->right, value, sum);
    }
    
public:
    int sumRootToLeaf(TreeNode *root) {
        int sum = 0;
        rec(root, 0, sum);
        return sum;
    }
};