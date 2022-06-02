class Solution {
public:
    string tree2str(TreeNode *root) {
        string res = to_string(root->val);
        
        if (root->left || root->right) {
            res += "(";
            if (root->left)
                res += tree2str(root->left);
            res += ")";
        }
        
        if (root->right) {
            res += "(";
            res += tree2str(root->right);
            res += ")";
        }
        
        return res;
    }
};