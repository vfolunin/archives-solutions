class Solution {
    TreeNode *reconstruct(vector<int> &pre, int preL, int preR,
                          vector<int> &post, int postL, int postR) {
        if (preL > preR)
            return 0;
        
        if (preL == preR)
            return new TreeNode(pre[preL]);
        
        int lSize = 1;
        while (pre[preL + 1] != post[postL + lSize - 1])
            lSize++;

        TreeNode *n = new TreeNode(pre[preL]);
        n->left = reconstruct(pre, preL + 1, preL + lSize, post, postL, postL + lSize - 1);
        n->right = reconstruct(pre, preL + 1 + lSize, preR, post, postL + lSize, postR - 1);
        return n;
    }
    
public:
    TreeNode *constructFromPrePost(vector<int> &preorder, vector<int> &postorder) {
        return reconstruct(preorder, 0, preorder.size() - 1, postorder, 0, postorder.size() - 1);
    }
};