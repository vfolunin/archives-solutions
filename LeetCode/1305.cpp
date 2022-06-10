class Solution {
    void traverse(TreeNode *n, vector<int> &values) {
        if (!n)
            return;
        traverse(n->left, values);
        values.push_back(n->val);
        traverse(n->right, values);
    }
    
public:
    vector<int> getAllElements(TreeNode *na, TreeNode *nb) {
        vector<int> res;
        traverse(na, res);
        traverse(nb, res);
        sort(res.begin(), res.end());
        return res;
    }
};