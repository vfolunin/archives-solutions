class Solution {
    void rec1(TreeNode *n, TreeNode *p, int depth, unordered_map<int, int> &depthSum, unordered_map<TreeNode *, int> &parentSum) {
        if (!n)
            return;

        depthSum[depth] += n->val;
        parentSum[p] += n->val;

        rec1(n->left, n, depth + 1, depthSum, parentSum);
        rec1(n->right, n, depth + 1, depthSum, parentSum);
    }

    void rec2(TreeNode *n, TreeNode *p, int depth, unordered_map<int, int> &depthSum, unordered_map<TreeNode *, int> &parentSum) {
        if (!n)
            return;

        n->val = depthSum[depth] - parentSum[p];

        rec2(n->left, n, depth + 1, depthSum, parentSum);
        rec2(n->right, n, depth + 1, depthSum, parentSum);
    }

public:
    TreeNode *replaceValueInTree(TreeNode *root) {
        unordered_map<int, int> depthSum;
        unordered_map<TreeNode *, int> parentSum;

        rec1(root, 0, 0, depthSum, parentSum);
        rec2(root, 0, 0, depthSum, parentSum);

        return root;
    }
};