class Solution {
    pair<Node *, Node *> rec(Node *n) {
        if (!n)
            return { 0, 0 };
        
        auto [ll, lr] = rec(n->left);
        auto [rl, rr] = rec(n->right);

        if (lr) {
            n->left = lr;
            lr->right = n;
        }
        if (rl) {
            n->right = rl;
            rl->left = n;
        }

        return { ll ? ll : n, rr ? rr : n };
    }

public:
    Node *treeToDoublyList(Node *root) {
        if (!root)
            return 0;
            
        auto [l, r] = rec(root);
        l->left = r;
        r->right = l;
        return l;
    }
};