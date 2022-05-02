class Solution {
public:
    TreeNode *getTargetCopy(TreeNode *original, TreeNode *cloned, TreeNode *target) {
        if (!original)
            return 0;
        
        if (original == target)
            return cloned;
        
        if (TreeNode *leftRes = getTargetCopy(original->left, cloned->left, target); leftRes)
            return leftRes;
        return getTargetCopy(original->right, cloned->right, target);
    }
};