class Solution {
public:
    int kthSmallest(TreeNode *n, int &k) {
        if (!n)
            return -1;
        if (int res = kthSmallest(n->left, k); res != -1)
            return res;
        if (k-- == 1)
            return n->val;
        return kthSmallest(n->right, k);
    }
};