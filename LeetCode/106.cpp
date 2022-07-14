class Solution {
    void reconstruct(TreeNode *n, vector<int> &postorder, int &pi, vector<int> &inorder, int il, int ir) {
        if (il == ir) {
            n->val = postorder[pi--];
            return;
        }
        
        n->val = postorder[pi];
        if (il < ir) {
            int im = find(inorder.begin() + il, inorder.begin() + ir + 1, postorder[pi--]) - inorder.begin();
            if (im < ir)
                reconstruct(n->right = new TreeNode(), postorder, pi, inorder, im + 1, ir);
            if (il < im)
                reconstruct(n->left = new TreeNode(), postorder, pi, inorder, il, im - 1);
        }
    }
    
public:
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        TreeNode *root = new TreeNode();
        int pi = postorder.size() - 1;
        reconstruct(root, postorder, pi, inorder, 0, inorder.size() - 1);
        return root;
    }
};