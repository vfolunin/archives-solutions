class Solution {
    vector<int> rec(TreeNode *n) {
        vector<int> res = { 0, n->val, n->val };
        
        if (n->left) {
            vector<int> l = rec(n->left);
            res[0] = max({ res[0], l[0], n->val - l[1], l[2] - n->val });
            res[1] = min(res[1], l[1]);
            res[2] = max(res[2], l[2]);
        }
        
        if (n->right) {
            vector<int> r = rec(n->right);
            res[0] = max({ res[0], r[0], n->val - r[1], r[2] - n->val });
            res[1] = min(res[1], r[1]);
            res[2] = max(res[2], r[2]);
        }
        
        return res;
    }
    
public:
    int maxAncestorDiff(TreeNode *root) {
        return rec(root)[0];
    }
};