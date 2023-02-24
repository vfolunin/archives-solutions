class Solution {
public:
    PolyNode *addPoly(PolyNode *a, PolyNode *b) {
        PolyNode head, *n = &head;

        while (a || b) {
            if (a && b && a->power == b->power) {
                if (a->coefficient + b->coefficient)
                    n = n->next = new PolyNode(a->coefficient + b->coefficient, a->power);
                a = a->next;
                b = b->next;
            } else if (!b || a && a->power > b->power) {
                n = n->next = new PolyNode(a->coefficient, a->power);
                a = a->next;
            } else {
                n = n->next = new PolyNode(b->coefficient, b->power);
                b = b->next;
            }
        }

        return head.next;
    }
};