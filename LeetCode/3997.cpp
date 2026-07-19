class Solution {
    pair<int, int> rec(TreeNode *v) {
        if (!v)
            return { 0, 0 };
        
        int maxValue = v->val, dominantCount = 0;
        for (TreeNode *to : { v->left, v->right }) {
            auto [toMaxValue, toDominantCount] = rec(to);
            maxValue = max(maxValue, toMaxValue);
            dominantCount += toDominantCount;
        }
        dominantCount += v->val == maxValue;

        return { maxValue, dominantCount };
    }

public:
    int countDominantNodes(TreeNode *root) {
        return rec(root).second;
    }
};