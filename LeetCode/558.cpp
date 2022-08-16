class Solution {
public:
    Node *intersect(Node *a, Node *b) {
        if (a->isLeaf)
            return a->val ? a : b;
        if (b->isLeaf)
            return b->val ? b : a;
        
        Node *tl = intersect(a->topLeft, b->topLeft);
        Node *tr = intersect(a->topRight, b->topRight);
        Node *bl = intersect(a->bottomLeft, b->bottomLeft);
        Node *br = intersect(a->bottomRight, b->bottomRight);
        
        if (tl->isLeaf && tr->isLeaf && bl->isLeaf && br->isLeaf &&
            tl->val == tr->val && tl->val == bl->val && tl->val == br->val)
            return new Node(tl->val, 1);
        else
            return new Node(0, 0, tl, tr, bl, br);
    }
};