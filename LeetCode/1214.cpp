class Solution {
    void traverse(TreeNode *n, vector<int> &res) {
        if (!n)
            return;
        traverse(n->left, res);
        res.push_back(n->val);
        traverse(n->right, res);
    }

public:
    bool twoSumBSTs(TreeNode *aRoot, TreeNode *bRoot, int target) {
        vector<int> a;
        traverse(aRoot, a);
        
        vector<int> b;
        traverse(bRoot, b);

        for (int ai = 0, bi = (int)b.size() - 1; ai < a.size() && bi >= 0; ai++) {
            while (bi >= 0 && a[ai] + b[bi] > target)
                bi--;
            if (bi >= 0 && a[ai] + b[bi] == target)
                return 1;
        }

        return 0;
    }
};