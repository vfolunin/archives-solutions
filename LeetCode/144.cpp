class Solution {
    void traverse(TreeNode *n, vector<int> &order) {
        if (!n)
            return;
        order.push_back(n->val);
        traverse(n->left, order);
        traverse(n->right, order);
    }
    
public:
    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> order;
        traverse(root, order);
        return order;
    }
};