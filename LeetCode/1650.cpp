class Solution {
public:
    Node *lowestCommonAncestor(Node *a, Node *b) {
        unordered_set<Node *> aAncestors;
        for ( ; a; a = a->parent) 
            aAncestors.insert(a);
        
        while (!aAncestors.count(b))
            b = b->parent;
        return b;
    }
};