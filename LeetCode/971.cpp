class Solution {
    bool rec(TreeNode *n, vector<int> &preorder, int &i, vector<int> &res) {
        if (n->val != preorder[i])
            return 0;
        
        if (n->left && n->right && n->left->val != preorder[i + 1]) {
            swap(n->left, n->right);
            res.push_back(n->val);
        }
        
        bool ok = 1;
        if (n->left)
            ok &= rec(n->left, preorder, ++i, res);
        if (n->right)
            ok &= rec(n->right, preorder, ++i, res);
        return ok;
    }
    
public:
    vector<int> flipMatchVoyage(TreeNode *root, vector<int> &preorder) {
        int i = 0;
        vector<int> res;
        if (rec(root, preorder, i, res))
            return res;
        return { -1 };
    }
};