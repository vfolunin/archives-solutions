class Solution {
public:
    Node *insert(Node *head, int value) {
        if (!head) {
            head = new Node(value);
            head->next = head;
            return head;
        }

        Node *n = head;
        for (int i = 0; i < 6e4; i++) {
            if (n->val <= value && value <= n->next->val ||
                n->next->val < n->val && (n->val <= value || value <= n->next->val)) {
                n->next = new Node(value, n->next);
                return head;
            }
            n = n->next;
        }

        head->next = new Node(value, head->next);
        return head;
    }
};