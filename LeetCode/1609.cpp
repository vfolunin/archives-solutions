class Solution {
    bool rec(TreeNode *n, int depth, vector<int> &last) {
        if (!n)
            return 1;
        
        if (n->val % 2 == depth % 2)
            return 0;
        
        if (last.size() == depth)
            last.push_back(n->val);
        else if (depth % 2 == 0 && last[depth] < n->val || depth % 2 && last[depth] > n->val)
            last[depth] = n->val;
        else
            return 0;
        
        return rec(n->left, depth + 1, last) && rec(n->right, depth + 1, last);
    }
    
public:
    bool isEvenOddTree(TreeNode *root) {
        vector<int> last;
        return rec(root, 0, last);
    }
};