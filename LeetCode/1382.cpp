class Solution {
    void traverse(TreeNode *n, vector<int> &values) {
        if (!n)
            return;
        traverse(n->left, values);
        values.push_back(n->val);
        traverse(n->right, values);
    }
    
    TreeNode *build(vector<int> &values, int l, int r) {
        int m = l + (r - l) / 2;
        TreeNode *n = new TreeNode(values[m]);
        if (l < m)
            n->left = build(values, l, m - 1);
        if (m < r)
            n->right = build(values, m + 1, r);
        return n;
    }
    
public:
    TreeNode *balanceBST(TreeNode *root) {
        vector<int> values;
        traverse(root, values);
        return build(values, 0, values.size() - 1);        
    }
};