class Codec {
public:
    TreeNode *encode(Node *n) {
        if (!n)
            return 0;

        TreeNode *tn = new TreeNode(n->val);
        if (!n->children.empty()) {
            TreeNode *next = tn->left = encode(n->children[0]);
            for (int i = 1; i < n->children.size(); i++)
                next = next->right = encode(n->children[i]);
        }
        return tn;
    }
	
    Node *decode(TreeNode *tn) {
        if (!tn)
            return 0;
        
        Node *n = new Node(tn->val);
        for (TreeNode *next = tn->left; next; next = next->right)
            n->children.push_back(decode(next));
        return n;
    }
};