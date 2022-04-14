class Solution {
    void traverse(TreeNode *n, vector<int> &order) {
        if (!n)
            return;
        traverse(n->left, order);
        traverse(n->right, order);
        order.push_back(n->val);
    }
    
public:
    vector<int> postorderTraversal(TreeNode *root) {
        vector<int> order;
        traverse(root, order);
        return order;
    }
};