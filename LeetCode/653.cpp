class Solution {
    bool rec(TreeNode *n, int target, unordered_set<int> &seen) {
        if (!n)
            return 0;
        
        if (seen.count(target - n->val))
            return 1;
        
        seen.insert(n->val);
        return rec(n->left, target, seen) || rec(n->right, target, seen);
    }
    
public:
    bool findTarget(TreeNode *root, int target) {
        unordered_set<int> seen;
        return rec(root, target, seen);
    }
};