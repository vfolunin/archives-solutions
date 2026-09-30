class Solution {
    void dfs(TreeNode *node, int depth, vector<vector<TreeNode *>> &levels) {
        if (!node)
            return;
        
        if (levels.size() == depth)
            levels.emplace_back();
        levels[depth].push_back(node);

        dfs(node->left, depth + 1, levels);
        dfs(node->right, depth + 1, levels);
    }

public:
    vector<long long> zigzagLevelSum(TreeNode *root) {
        vector<vector<TreeNode *>> levels;
        dfs(root, 0, levels);

        vector<long long> res(levels.size());
        for (int depth = 0; depth < levels.size(); depth++) {
            if (depth % 2)
                reverse(levels[depth].begin(), levels[depth].end());

            for (TreeNode *node : levels[depth]) {
                if (depth % 2 == 0 && node->left || depth % 2 == 1 && node->right)
                    res[depth] += node->val;
                else
                    break;
            }
        }
        return res;
    }
};