class Solution {
public:
    Node *copyRandomList(Node *head) {
        unordered_map<Node *, Node *> to;
        
        for (Node *n = head; n; n = n->next)
            to[n] = new Node(n->val);
        
        for (Node *n = head; n; n = n->next) {
            if (n->next)
                to[n]->next = to[n->next];
            to[n]->random = to[n->random];
        }
        
        return to[head];
    }
};