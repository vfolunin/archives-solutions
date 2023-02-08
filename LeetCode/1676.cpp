class Solution {
    int rec(TreeNode *n, unordered_set<TreeNode *> &nodeSet, TreeNode *&res) {
        if (!n)
            return 0;
        
        int lCount = rec(n->left, nodeSet, res);
        int rCount = rec(n->right, nodeSet, res);
        int totalCount = lCount + nodeSet.count(n) + rCount;

        if (totalCount == nodeSet.size() && !res)
            res = n;
        
        return totalCount;
    }

public:
    TreeNode *lowestCommonAncestor(TreeNode *root, vector<TreeNode *> &nodes) {
        unordered_set<TreeNode *> nodeSet(nodes.begin(), nodes.end());
        TreeNode *res = 0;
        rec(root, nodeSet, res);
        return res;
    }
};