class Solution {
    tuple<bool, int, int, int, int> rec(TreeNode *n) {
        if (!n)
            return { 1, 1e9, -1e9, 0, 0 };
        
        auto [lBst, lMin, lMax, lSize, lRes] = rec(n->left);
        auto [rBst, rMin, rMax, rSize, rRes] = rec(n->right);

        bool bst = lBst && lMax < n->val && n->val < rMin && rBst;
        int size = lSize + 1 + rSize;
        int res = max({ lRes, bst ? size : 0, rRes });
        return { bst, min(lMin, n->val), max(rMax, n->val), size, res };
    }

public:
    int largestBSTSubtree(TreeNode *root) {
        auto [bst, min, max, size, res] = rec(root);
        return res;
    }
};