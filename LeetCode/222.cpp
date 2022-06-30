class Solution {
public:
    int countNodes(TreeNode *n) {
        if (!n)
            return 0;
        return countNodes(n->left) + 1 + countNodes(n->right);
    }
};