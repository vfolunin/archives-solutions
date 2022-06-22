class Codec {
    void serialize(TreeNode *n, stringstream &ss) {
        if (!n) {
            ss << 1001 << " ";
            return;
        }
        
        ss << n->val << " ";
        serialize(n->left, ss);
        serialize(n->right, ss);
    }
    
    TreeNode *deserialize(stringstream &ss) {
        int val;
        ss >> val;
        
        if (val == 1001)
            return 0;
        
        TreeNode *n = new TreeNode(val);
        n->left = deserialize(ss);
        n->right = deserialize(ss);
        return n;
    }
    
public:
    string serialize(TreeNode *root) {
        stringstream ss;
        serialize(root, ss);
        return ss.str();
    }

    TreeNode *deserialize(const string &data) {
        stringstream ss(data);
        return deserialize(ss);
    }
};