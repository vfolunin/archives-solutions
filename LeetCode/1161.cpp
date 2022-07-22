class Solution {
    void rec(TreeNode *n, int depth, vector<int> &sum) {
        if (!n)
            return;
        
        if (depth == sum.size())
            sum.emplace_back();
        sum[depth] += n->val;
        
        rec(n->left, depth + 1, sum);
        rec(n->right, depth + 1, sum);
    }
    
public:
    int maxLevelSum(TreeNode *root) {
        vector<int> sum;
        rec(root, 0, sum);
        return max_element(sum.begin(), sum.end()) - sum.begin() + 1;
    }
};