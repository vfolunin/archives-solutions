class Solution {
    void dfs(TreeNode *n, int depth, vector<vector<int>> &a) {
        if (!n)
            return;
        
        if (a.size() == depth)
            a.emplace_back();
        
        a[depth].push_back(n->val);
        
        dfs(n->left, depth + 1, a);
        dfs(n->right, depth + 1, a);
    }
    
    int swapCount(vector<int> &a) {
        vector<int> sortedA = a;
        sort(sortedA.begin(), sortedA.end());
        
        for (int &value : a)
            value = lower_bound(sortedA.begin(), sortedA.end(), value) - sortedA.begin();
        
        int res = 0;
        for (int i = 0; i < a.size(); i++) {
            while (a[i] != i) {
                swap(a[i], a[a[i]]);
                res++;
            }
        }
        return res;
    }
    
public:
    int minimumOperations(TreeNode *root) {
        vector<vector<int>> a;
        dfs(root, 0, a);
        
        int res = 0;
        for (vector<int> &level : a)
            res += swapCount(level);
        return res;
    }
};