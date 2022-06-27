class Solution {
    void makeDepths(TreeNode *n, int depth, unordered_map<TreeNode *, int> &depths) {
        if (!n)
            return;
        
        depths[n] = depth;
        makeDepths(n->left, depth + 1, depths);
        makeDepths(n->right, depth + 1, depths);
    }
    
    int makeCounts(TreeNode *n, int depth, int targetDepth, unordered_map<TreeNode *, int> &counts) {
        if (!n)
            return 0;
        
        counts[n] = depth == targetDepth;
        counts[n] += makeCounts(n->left, depth + 1, targetDepth, counts);
        counts[n] += makeCounts(n->right, depth + 1, targetDepth, counts);
        
        return counts[n];
    }
    
public:
    TreeNode *subtreeWithAllDeepest(TreeNode *root) {
        unordered_map<TreeNode *, int> depths;
        makeDepths(root, 0, depths);
        
        int maxDepth = 0;
        for (auto &[n, depth] : depths)
            maxDepth = max(maxDepth, depth);
        
        unordered_map<TreeNode *, int> counts;
        makeCounts(root, 0, maxDepth, counts);
        
        int targetCount = counts[root];
        
        while (counts[root->left] == targetCount || counts[root->right] == targetCount)
            root = counts[root->left] == targetCount ? root->left : root->right;
        
        return root;
    }
};