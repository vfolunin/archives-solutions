class Solution {
    struct Data {
        int longestPathToTheLeft;
        int longestPathToTheRight;
        int pathToStart;
        int longestPathFromStart;
    };
    
    Data rec(TreeNode *n, int start) {
        if (!n)
            return { -1, -1, -1, -1 };
        
        auto [ll, lr, ls, lRes] = rec(n->left, start);
        auto [rl, rr, rs, rRes] = rec(n->right, start);
        
        if (n->val == start)
            return { 0, 0, 0, 1 + max({ ll, lr, rl, rr }) };
        else if (ls != -1)
            return { 1 + max(ll, lr), 1 + max(rl, rr), 1 + ls, max(lRes, 2 + ls + max(rl, rr)) };
        else if (rs != -1)
            return { 1 + max(ll, lr), 1 + max(rl, rr), 1 + rs, max(rRes, 2 + rs + max(ll, lr)) };
        else
            return { 1 + max(ll, lr), 1 + max(rl, rr), -1, -1 };
    }
    
public:
    int amountOfTime(TreeNode *root, int start) {
        return rec(root, start).longestPathFromStart;
    }
};