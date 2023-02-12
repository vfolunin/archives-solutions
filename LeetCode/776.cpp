class Solution {
public:
    vector<TreeNode *> splitBST(TreeNode *n, int target) {
        if (!n)
            return { 0, 0 };
        if (n->val <= target) {
            vector<TreeNode *> s = splitBST(n->right, target);
            n->right = s[0];
            return { n, s[1] };
        } else {
            vector<TreeNode *> s = splitBST(n->left, target);
            n->left = s[1];
            return { s[0], n };
        }
    }
};