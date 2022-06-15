class Solution {
    pair<int, int> rec(TreeNode *n) {
        if (!n)
            return { 0, 0 };
        auto [hl, dl] = rec(n->left);
        auto [hr, dr] = rec(n->right);
        return { 1 + max(hl, hr), max({ dl, dr, hl + 1 + hr }) };
    }

public:
    int diameterOfBinaryTree(TreeNode *root) {
        return root ? rec(root).second - 1 : 0;
    }
};