class Solution {
    pair<int, int> rec(TreeNode *n, int index) {
        if (!n)
            return { 0, -1 };
        
        auto [lSize, lMaxIndex] = rec(n->left, min<int>(index * 2 + 1, 1e9));
        auto [rSize, rMaxIndex] = rec(n->right, min<int>(index * 2 + 2, 1e9));
        return { lSize + 1 + rSize, max({ lMaxIndex, index, rMaxIndex }) };
    }
    
public:
    bool isCompleteTree(TreeNode *root) {
        auto [size, maxIndex] = rec(root, 0);
        return size == maxIndex + 1;
    }
};