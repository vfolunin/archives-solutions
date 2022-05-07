class Solution {
    void rec(TreeNode *n, int depth, vector<pair<double, double>> &fractions) {
        if (!n)
            return;
    
        if (fractions.size() == depth)
            fractions.emplace_back();
        
        fractions[depth].first += n->val;
        fractions[depth].second++;
        
        rec(n->left, depth + 1, fractions);
        rec(n->right, depth + 1, fractions);
    }
    
public:
    vector<double> averageOfLevels(TreeNode *root) {
        vector<pair<double, double>> fractions;
        rec(root, 0, fractions);
        
        vector<double> res(fractions.size());
        for (int i = 0; i < res.size(); i++)
            res[i] = fractions[i].first / fractions[i].second;
        return res;
    }
};