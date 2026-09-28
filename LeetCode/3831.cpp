class Solution {
    void dfs(TreeNode *node, int depth, vector<vector<int>> &levels) {
        if (!node)
            return;
        
        if (levels.size() == depth)
            levels.emplace_back();
        levels[depth].push_back(node->val);

        dfs(node->left, depth + 1, levels);
        dfs(node->right, depth + 1, levels);
    }

public:
    int levelMedian(TreeNode *root, int levelIndex) {
        vector<vector<int>> levels;
        dfs(root, 0, levels);

        if (levelIndex >= levels.size())
            return -1;

        vector<int> &level = levels[levelIndex];
        nth_element(level.begin(), level.begin() + level.size() / 2, level.end());
        return level[level.size() / 2];
    }
};