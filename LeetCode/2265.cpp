class Solution {
    struct Data {
        int sum, size, count;
    };
    
    Data rec(TreeNode *n) {
        if (!n)
            return { 0, 0, 0 };
        
        auto [lSum, lSize, lCount] = rec(n->left);
        auto [rSum, rSize, rCount] = rec(n->right);
        
        int sum = lSum + n->val + rSum;
        int size = lSize + 1 + rSize;
        int count = lCount + (sum / size == n->val) + rCount;
        
        return { sum, size, count };
    }
    
public:
    int averageOfSubtree(TreeNode *root) {
        return rec(root).count;
    }
};