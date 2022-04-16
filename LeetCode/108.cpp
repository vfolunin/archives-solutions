class Solution {
    TreeNode *build(vector<int> &a, int l, int r) {
        if (l > r)
            return 0;        
        int m = l + (r - l) / 2;
        return new TreeNode(a[m], build(a, l, m - 1), build(a, m + 1, r));
    }
    
public:
    TreeNode *sortedArrayToBST(vector<int> &a) {
        return build(a, 0, a.size() - 1);
    }
};