class BSTIterator {
    vector<TreeNode *> nodes;
    int i = -1;

    void rec(TreeNode *n) {
        if (!n)
            return;

        rec(n->left);
        nodes.push_back(n);
        rec(n->right);
    }

public:
    BSTIterator(TreeNode *root) {
        rec(root);
    }
    
    int next() {
        return nodes[++i]->val;
    }
    
    bool hasNext() {
        return i + 1 < nodes.size();
    }
    
    int prev() {
        return nodes[--i]->val;
    }
    
    bool hasPrev() {
        return 0 < i;
    }
};