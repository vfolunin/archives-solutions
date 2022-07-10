class Solution {
public:
    bool evaluateTree(TreeNode *n) {
        if (!n->left && !n->right)
            return n->val;
        
        bool l = evaluateTree(n->left);
        bool r = evaluateTree(n->right);
        return n->val == 2 ? l || r : l && r;
    }
};