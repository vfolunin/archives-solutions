class Solution {    
    void rec(TreeNode *n, int depth, unsigned int index, vector<unsigned int> &first, vector<unsigned int> &last) {
        if (!n)
            return;
        
        if (depth == first.size()) {
            first.push_back(index);
            last.push_back(index);
        } else {
            first[depth] = min(first[depth], index);
            last[depth] = max(last[depth], index);
        }
        
        rec(n->left, depth + 1, index * 2, first, last);
        rec(n->right, depth + 1, index * 2 + 1, first, last);
    }
    
public:
    int widthOfBinaryTree(TreeNode *root) {
        vector<unsigned int> first, last;
        rec(root, 0, 0, first, last);
        
        unsigned int res = 0;
        for (int i = 0; i < first.size(); i++)
            res = max(res, last[i] - first[i] + 1);
        return res;
    }
};