class Solution {
    TreeNode *construct(stringstream &ss) {
        int value;
        ss >> value;
        TreeNode *res = new TreeNode(value);

        if (ss.peek() == '(') {
            ss.get();
            res->left = construct(ss);
            ss.get();
        }

        if (ss.peek() == '(') {
            ss.get();
            res->right = construct(ss);
            ss.get();
        }

        return res;
    }

public:
    TreeNode *str2tree(string &s) {
        if (s.empty())
            return 0;
            
        stringstream ss(s);
        return construct(ss);
    }
};