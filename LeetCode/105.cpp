class Solution {
    void reconstruct(TreeNode *n, vector<int> &preorder, int &pi, vector<int> &inorder, int il, int ir) {
        if (il == ir) {
            n->val = preorder[pi++];
            return;
        }
        
        n->val = preorder[pi];
        if (il < ir) {
            int im = find(inorder.begin() + il, inorder.begin() + ir + 1, preorder[pi++]) - inorder.begin();
            if (il < im)
                reconstruct(n->left = new TreeNode(), preorder, pi, inorder, il, im - 1);
            if (im < ir)
                reconstruct(n->right = new TreeNode(), preorder, pi, inorder, im + 1, ir);
        }
    }
    
public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        TreeNode *root = new TreeNode();
        int pi = 0;
        reconstruct(root, preorder, pi, inorder, 0, inorder.size() - 1);
        return root;
    }
};