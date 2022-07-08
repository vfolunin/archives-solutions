class Solution {
public:
    Node *flatten(Node *head) {
        for (Node *n = head; n; n = n->next) {
            if (n->child) {
                Node *tail = n->next;
                Node *child = flatten(n->child);
                n->child = 0;
                
                n->next = child;
                child->prev = n;
                
                while (n->next)
                    n = n->next;
                
                n->next = tail;
                if (tail)
                    tail->prev = n;
            }
        }
        
        return head;
    }
};