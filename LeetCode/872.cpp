class Solution {
    void rec(TreeNode *n, vector<int> &leaves) {
        if (!n)
            return;
        if (!n->left && !n->right)
            leaves.push_back(n->val);
        rec(n->left, leaves);
        rec(n->right, leaves);
    }
    
public:
    bool leafSimilar(TreeNode *a, TreeNode *b) {
        vector<int> aLeaves, bLeaves;
        rec(a, aLeaves);
        rec(b, bLeaves);
        return aLeaves == bLeaves;
    }
};