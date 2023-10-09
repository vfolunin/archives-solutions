class Solution {
    unordered_set<TreeNode *> getLeaves(TreeNode *n) {
        unordered_set<TreeNode *> seen;
        while (n && !seen.count(n)) {
            seen.insert(n);
            n = n->left ? n->left : n->right;
        }
        
        unordered_set<TreeNode *> leaves;
        while (n && !leaves.count(n)) {
            leaves.insert(n);
            n = n->left;
        }
        return leaves;
    }

    int getHeight(TreeNode *n, unordered_set<TreeNode *> &leaves) {
        if (!n)
            return -1;
        if (leaves.count(n))
            return 0;
        return 1 + max(getHeight(n->left, leaves), getHeight(n->right, leaves));
    }

public:
    int heightOfTree(TreeNode *root) {
        unordered_set<TreeNode *> leaves = getLeaves(root);
        return getHeight(root, leaves);
    }
};