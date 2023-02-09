class Solution {
    void rec(Node *n, unordered_map<Node *, NodeCopy *> &to) {
        if (!n)
            return;
        
        rec(n->left, to);
        rec(n->right, to);

        to[n] = new NodeCopy(n->val, to[n->left], to[n->right], 0);
    }

public:
    NodeCopy *copyRandomBinaryTree(Node *root) {
        unordered_map<Node *, NodeCopy *> to;
        rec(root, to);

        for (auto &[n, nc] : to)
            if (n && n->random)
                nc->random = to[n->random];
        
        return to[root];
    }
};