class Solution {
    TreeNode *rec(vector<int> &a, int l, int r) {
        if (l > r)
            return 0;
        
        int m = l + 1;
        while (m <= r && a[m] < a[l])
            m++;
        
        return new TreeNode(a[l], rec(a, l + 1, m - 1), rec(a, m, r));
    }
    
public:
    TreeNode *bstFromPreorder(vector<int> &a) {
        return rec(a, 0, a.size() - 1);
    }
};