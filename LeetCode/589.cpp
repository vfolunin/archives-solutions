class Solution {
    void traverse(Node *n, vector<int> &order) {
        if (!n)
            return;
        order.push_back(n->val);
        for (Node *to : n->children)
            traverse(to, order);
    }
    
public:
    vector<int> preorder(Node *root) {
        vector<int> order;
        traverse(root, order);
        return order;
    }
};