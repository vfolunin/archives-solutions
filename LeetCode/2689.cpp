class Solution {
    int getLen(RopeTreeNode *n) {
        if (!n)
            return 0;
        if (n->len)
            return n->len;
        return n->val.size();
    }

public:
    char getKthCharacter(RopeTreeNode *n, int k) {
        if (!n->len)
            return n->val[k - 1];
        
        int leftLen = getLen(n->left);
        if (k <= leftLen)
            return getKthCharacter(n->left, k);
        else
            return getKthCharacter(n->right, k - leftLen);
    }
};