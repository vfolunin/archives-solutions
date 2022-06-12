class Solution {
    void traverse(Node *n, vector<int> &order) {
        if (!n)
            return;
        for (Node *to : n->children)
            traverse(to, order);
        order.push_back(n->val);
    }
    
public:
    vector<int> postorder(Node *root) {
        vector<int> order;
        traverse(root, order);
        return order;
    }
};