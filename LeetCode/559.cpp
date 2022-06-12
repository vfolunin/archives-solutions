class Solution {
public:
    int maxDepth(Node *n) {
        if (!n)
            return 0;
        
        int res = 0;
        for (Node *child : n->children)
            res = max(res, maxDepth(child));
        return res + 1;
    }
};