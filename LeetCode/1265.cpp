class Solution {
public:
    void printLinkedListInReverse(ImmutableListNode *n) {
        if (!n)
            return;

        printLinkedListInReverse(n->getNext());
        n->printValue();
    }
};