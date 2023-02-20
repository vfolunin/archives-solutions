class Solution {
    void recLeaves(TreeNode *n, vector<int> &leaves) {
        if (!n)
            return;
        if (!n->left && !n->right)
            leaves.push_back(n->val);        
        recLeaves(n->left, leaves);
        recLeaves(n->right, leaves);
    }

    void recLeft(TreeNode *n, vector<int> &left) {
        if (n->left || n->right)
            left.push_back(n->val);
        if (n->left)
            recLeft(n->left, left);
        else if (n->right)
            recLeft(n->right, left);
    }

    void recRight(TreeNode *n, vector<int> &right) {
        if (n->left || n->right)
            right.push_back(n->val);
        if (n->right)
            recRight(n->right, right);
        else if (n->left)
            recRight(n->left, right);
    }

public:
    vector<int> boundaryOfBinaryTree(TreeNode *root) {
        vector<int> res = { root->val };

        if (root->left) {
            vector<int> left;
            recLeft(root->left, left);
            res.insert(res.end(), left.begin(), left.end());
        }

        if (root->left || root->right) {
            vector<int> leaves;
            recLeaves(root, leaves);
            res.insert(res.end(), leaves.begin(), leaves.end());
        }
        
        if (root->right) {
            vector<int> right;
            recRight(root->right, right);
            res.insert(res.end(), right.rbegin(), right.rend());
        }

        return res;
    }
};