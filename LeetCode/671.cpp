class Solution {
    void rec(TreeNode *n, int min1, int &min2) {
        if (!n)
            return;
        if (min1 < n->val && (min2 == -1 || n->val < min2)) {
            min2 = n->val;
        } else if (min1 == n->val) {
            rec(n->left, min1, min2);
            rec(n->right, min1, min2);
        }
    }
    
public:
    int findSecondMinimumValue(TreeNode *root) {
        int res = -1;
        rec(root, root->val, res);
        return res;
    }
};