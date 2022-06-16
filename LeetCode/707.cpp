class MyLinkedList {
    struct Node {
        int val;
        Node *prev, *next;
        Node(int val, Node *prev = 0, Node *next = 0) : val(val), prev(prev), next(next) {}
    } *head, *tail;
    
    Node *getNode(int index) {
        Node *n = head->next;
        for (int i = 0; i < index && n; i++)
            n = n->next;
        return n;
    }
    
public:
    MyLinkedList() {
        head = new Node(0);
        tail = new Node(0, head);
        head->next = tail;
    }
    
    int get(int index) {
        if (Node *n = getNode(index); n && n != tail)
            return n->val;
        return -1;
    }
    
    void addAtHead(int val) {
        head->next = head->next->prev = new Node(val, head, head->next);
    }
    
    void addAtTail(int val) {
        tail->prev = tail->prev->next = new Node(val, tail->prev, tail);
    }
    
    void addAtIndex(int index, int val) {
        if (Node *n = getNode(index); n)
            n->prev = n->prev->next = new Node(val, n->prev, n);
    }
    
    void deleteAtIndex(int index) {
        if (Node *n = getNode(index); n && n != tail) {
            n->prev->next = n->next;
            n->next->prev = n->prev;
            delete n;
        }
    }
};