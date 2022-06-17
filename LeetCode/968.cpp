class Solution {    
    vector<int> rec(TreeNode *n) {
        if (!n)
            return { 0, 0, (int)1e9 };
        
        vector<int> l = rec(n->left);
        vector<int> r = rec(n->right);
        
        return {
            l[1] + r[1],
            min({ l[1] + r[2], l[2] + r[1], l[2] + r[2] }),
            min({ l[0], l[1], l[2] }) + min({ r[0], r[1], r[2] }) + 1
        };
    }
    
public:
    int minCameraCover(TreeNode *root) {
        vector<int> res = rec(root);
        return min(res[1], res[2]);
    }
};