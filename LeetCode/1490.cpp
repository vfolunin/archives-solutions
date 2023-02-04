class Solution {
public:
    Node *cloneTree(Node *n) {
        if (!n)
            return n;
        
        vector<Node *> children;
        for (Node *child : n->children)
            children.push_back(cloneTree(child));

        return new Node(n->val, children);
    }
};