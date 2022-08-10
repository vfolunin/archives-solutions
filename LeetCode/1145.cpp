class Solution {    
    pair<int, bool> rec(TreeNode *n, int size, int val) {
        if (!n)
            return { 0, 0 };
        
        auto [lSize, lWin] = rec(n->left, size, val);
        auto [rSize, rWin] = rec(n->right, size, val);
        int nSize = lSize + 1 + rSize;
        bool nWin = lWin || rWin;
        
        if (n->val == val) {
            nWin |= lSize > size - lSize;
            nWin |= rSize > size - rSize;
            nWin |= nSize < size - nSize;
        }
        
        return { nSize, nWin };
    }
    
public:
    bool btreeGameWinningMove(TreeNode *root, int size, int val) {
        return rec(root, size, val).second;
    }
};