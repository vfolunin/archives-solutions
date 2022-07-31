class Solution {
    pair<int, vector<int>> rec(TreeNode *n, int dist) {
        if (!n)
            return { 0, {} };
        
        if (!n->left && !n->right)
            return { 0, { 1 } };
        
        auto [lPairs, lDepths] = rec(n->left, dist);
        auto [rPairs, rDepths] = rec(n->right, dist);
        
        int pairs = lPairs + rPairs;
        for (int l = 0; l <= dist; l++)
            for (int r = 0; l + r + 2 <= dist; r++)
                pairs += (l < lDepths.size() ? lDepths[l] : 0) *
                         (r < rDepths.size() ? rDepths[r] : 0);
        
        vector<int> depths(max(lDepths.size(), rDepths.size()));
        for (int i = 0; i < depths.size(); i++)
            depths[i] = (i < lDepths.size() ? lDepths[i] : 0) +
                        (i < rDepths.size() ? rDepths[i] : 0);
        depths.insert(depths.begin(), 0);
            
        return { pairs, depths };
    }
    
public:
    int countPairs(TreeNode *root, int dist) {
        return rec(root, dist).first;
    }
};