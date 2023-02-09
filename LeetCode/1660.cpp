class Solution {
    void rec(TreeNode *&n, int curDepth, unordered_map<TreeNode *, int> &depth) {
        if (!n)
            return;
        
        depth[n] = curDepth;
        if (depth[n->left] == depth[n] || depth[n->right] == depth[n]) {
            n = 0;
            return;
        }

        rec(n->right, curDepth + 1, depth);
        rec(n->left, curDepth + 1, depth);
    }

public:
    TreeNode *correctBinaryTree(TreeNode *root) {
        unordered_map<TreeNode *, int> depth;
        rec(root, 1, depth);
        return root;
    }
};