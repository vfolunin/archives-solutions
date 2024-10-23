class Solution {
    void rec1(TreeNode *n, TreeNode *p, int depth, vector<int> &depthSum) {
        if (!n)
            return;

        if (depthSum.size() == depth)
            depthSum.emplace_back();
        depthSum[depth] += n->val;

        rec1(n->left, n, depth + 1, depthSum);
        rec1(n->right, n, depth + 1, depthSum);
    }

    void rec2(TreeNode *n, TreeNode *p, int depth, vector<int> &depthSum, int parentSum) {
        if (!n)
            return;

        n->val = depthSum[depth] - parentSum;
        int childSum = (n->left ? n->left->val : 0) + (n->right ? n->right->val : 0);

        rec2(n->left, n, depth + 1, depthSum, childSum);
        rec2(n->right, n, depth + 1, depthSum, childSum);
    }

public:
    TreeNode *replaceValueInTree(TreeNode *root) {
        vector<int> depthSum;

        rec1(root, 0, 0, depthSum);
        rec2(root, 0, 0, depthSum, root->val);
        
        return root;
    }
};