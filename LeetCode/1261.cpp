class FindElements {
    TreeNode *root;
    
public:
    FindElements(TreeNode *root) : root(root) {}
    
    bool find(int x) {
        x++;
        int bit = 20;
        while (!(x & (1 << bit)))
            bit--;
        
        TreeNode *n = root;
        for (bit--; bit >= 0; bit--) {
            TreeNode *to = x & (1 << bit) ? n->right : n->left;
            if (!to)
                return 0;
            n = to;
        }
        
        return 1;
    }
};