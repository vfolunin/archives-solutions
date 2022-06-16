class Solution {
    void rec(TreeNode *n, int &sum) {
        if (!n)
            return;
        rec(n->right, sum);
        sum += n->val;
        n->val = sum;
        rec(n->left, sum);
    }
    
public:    
    TreeNode *bstToGst(TreeNode *root) {
        int sum = 0;
        rec(root, sum);
        return root;
    }
};