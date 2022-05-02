class Solution {
public:
    int sumEvenGrandparent(TreeNode *n, TreeNode *p = 0, TreeNode *gp = 0) {
        if (!n)
            return 0;
        int res = (gp && gp->val % 2 == 0 ? n->val : 0);
        res += sumEvenGrandparent(n->left, n, p);
        res += sumEvenGrandparent(n->right, n, p);
        return res;
    }
};