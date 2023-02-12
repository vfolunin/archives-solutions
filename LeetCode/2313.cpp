class Solution {
    pair<int, int> rec(TreeNode *n) {
        if (!n)
            return { 0, 0 };
        if (n->val == 0)
            return { 0, 1 };
        if (n->val == 1)
            return { 1, 0 };
        
        auto [l0, l1] = rec(n->left);
        auto [r0, r1] = rec(n->right);

        if (n->val == 2)
            return { l0 + r0, min(l1, r1) };
        else if (n->val == 3)
            return { min(l0, r0), l1 + r1 };
        else if (n->val == 4)
            return { min(l0 + r0, l1 + r1), min(l0 + r1, l1 + r0) };
        else
            return { l1 + r1, l0 + r0 };
    }

public:
    int minimumFlips(TreeNode *root, bool target) {
        auto [res0, res1] = rec(root);
        return target ? res1 : res0;
    }
};