class BSTIterator {
    vector<TreeNode *> stack;

public:
    BSTIterator(TreeNode *root) {
        for (TreeNode *n = root; n; n = n->left)
            stack.push_back(n);
    }
    
    int next() {
        int value = stack.back()->val;
        
        if (stack.back()->right) {
            for (TreeNode *n = stack.back()->right; n; n = n->left)
                stack.push_back(n);
        } else {
            while (!stack.empty()) {
                TreeNode *child = stack.back();
                stack.pop_back();
                if (!stack.empty() && stack.back()->left == child)
                    break;
            }
        }

        return value;
    }
    
    bool hasNext() {
        return !stack.empty();
    }
};