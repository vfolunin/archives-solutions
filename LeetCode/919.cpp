class CBTInserter {
    TreeNode *root;
    int index;
    
    int getSize(TreeNode *n) {
        return n ? getSize(n->left) + 1 + getSize(n->right) : 0;
    }
    
public:
    CBTInserter(TreeNode *root) : root(root), index(getSize(root)) {}
    
    int insert(int val) {
        vector<int> path;
        for (int v = (index - 1) / 2; v; v = (v - 1) / 2)
            path.push_back(v);
        path.push_back(0);
        reverse(path.begin(), path.end());
        
        TreeNode *n = root;
        for (int i = 0; i + 1 < path.size(); i++)
            n = path[i] * 2 + 1 == path[i + 1] ? n->left : n->right;
        
        if (path.back() * 2 + 1 == index)
            n->left = new TreeNode(val);
        else
            n->right = new TreeNode(val);
        
        index++;
        return n->val;
    }
    
    TreeNode *get_root() {
        return root;
    }
};