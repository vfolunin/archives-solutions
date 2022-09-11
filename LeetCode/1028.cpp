class Solution {
    int readDepth(stringstream &ss) {
        int res = 0;
        while (ss.peek() == '-') {
            res++;
            ss.get();
        }
        return res;
    }
    
public:
    TreeNode *recoverFromPreorder(string &s) {
        vector<TreeNode *> branch(1000);
        
        stringstream ss(s);
        while (ss.peek() != EOF) {
            int depth = readDepth(ss);
            if (!depth)
                branch[depth] = new TreeNode;
            else if (!branch[depth - 1]->left)
                branch[depth] = branch[depth - 1]->left = new TreeNode;
            else
                branch[depth] = branch[depth - 1]->right = new TreeNode;
            ss >> branch[depth]->val;
        }
        
        return branch[0];
    }
};