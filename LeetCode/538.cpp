class Solution {
    int sum(TreeNode *n) {
        if (!n)
            return 0;
        return sum(n->left) + n->val + sum(n->right);
    }
    
public:
    TreeNode *convertBST(TreeNode *n, int add = 0) {
        if (!n)
            return n;
        int leftAdd = add + n->val + sum(n->right);
        return new TreeNode(leftAdd, convertBST(n->left, leftAdd), convertBST(n->right, add));
    }
};