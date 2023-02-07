class Solution {
    void rec(Node *n, string &leaves) {
        if (n->val == '+') {
            rec(n->left, leaves);
            rec(n->right, leaves);
        } else {
            leaves += n->val;
        }
    }

    string getLeaves(Node *n) {
        string leaves;
        rec(n, leaves);
        sort(leaves.begin(), leaves.end());
        return leaves;
    }

public:
    bool checkEquivalence(Node *a, Node *b) {
        return getLeaves(a) == getLeaves(b);
    }
};