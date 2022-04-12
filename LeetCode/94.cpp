class Solution {
    void traverse(TreeNode *n, vector<int> &order) {
        if (!n)
            return;
        traverse(n->left, order);
        order.push_back(n->val);
        traverse(n->right, order);
    }
    
public:
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> order;
        traverse(root, order);
        return order;
    }
};