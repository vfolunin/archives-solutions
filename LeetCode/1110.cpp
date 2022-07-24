class Solution {
    void rec(TreeNode *&n, unordered_set<int> &toDelete, vector<TreeNode *> &res) {
        if (!n)
            return;
        
        rec(n->left, toDelete, res);
        rec(n->right, toDelete, res);
        
        if (toDelete.count(n->val)) {
            if (n->left)
                res.push_back(n->left);
            if (n->right)
                res.push_back(n->right);
            n = 0;
        }
    }
    
public:
    vector<TreeNode *> delNodes(TreeNode *root, vector<int> &toDeleteVector) {
        unordered_set<int> toDelete(toDeleteVector.begin(), toDeleteVector.end());
        vector<TreeNode *> res;
        
        rec(root, toDelete, res);
        if (root)
            res.push_back(root);
        
        return res;
    }
};