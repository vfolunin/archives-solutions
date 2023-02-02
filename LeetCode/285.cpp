class Solution {
    void rec(TreeNode *n, map<int, TreeNode *> &nodes) {
        if (!n)
            return;

        nodes[n->val] = n;

        rec(n->left, nodes);
        rec(n->right, nodes);
    }

public:
    TreeNode *inorderSuccessor(TreeNode *root, TreeNode *n) {
        map<int, TreeNode *> nodes;
        rec(root, nodes);

        auto it = nodes.upper_bound(n->val);
        return it != nodes.end() ? it->second : 0;
    }
};