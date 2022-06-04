class Solution {
    unordered_map<int, int> depth, parent;
    
    void rec(TreeNode *n) {
        for (TreeNode *child : { n->left, n->right }) {
            if (child) {
                depth[child->val] = depth[n->val] + 1;
                parent[child->val] = n->val;
                rec(child);
            }
        }
    }
    
public:
    bool isCousins(TreeNode *root, int x, int y) {
        rec(root);
        return depth[x] == depth[y] && parent[x] != parent[y];
    }
};