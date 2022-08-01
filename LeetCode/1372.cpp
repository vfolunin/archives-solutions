class Solution {
    struct Data {
        int maxPath, leftPath, rightPath;
    };
    
    Data rec(TreeNode *n) {
        if (!n)
            return { 0, 0, 0 };
        
        auto [lm, ll, lr] = rec(n->left);
        auto [rm, rl, rr] = rec(n->right);
        
        int l = n->left ? 1 + lr : 0;
        int r = n->right ? 1 + rl : 0;
        return { max({ lm, rm, l, r }), l, r };
    }
    
public:
    int longestZigZag(TreeNode *root) {
        return rec(root).maxPath;
    }
};