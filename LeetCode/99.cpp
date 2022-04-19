class Solution {
    vector<int> values;
    
    void traverseRead(TreeNode *n) {
        if (!n)
            return;
        traverseRead(n->left);
        values.push_back(n->val);
        traverseRead(n->right);
    }
    
    void traverseWrite(TreeNode *n) {
        if (!n)
            return;
        traverseWrite(n->right);
        n->val = values.back();
        values.pop_back();
        traverseWrite(n->left);
    }
    
public:
    void recoverTree(TreeNode *root) {
        traverseRead(root);
        sort(values.begin(), values.end());
        traverseWrite(root);
    }
};