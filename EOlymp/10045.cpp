struct ListNode {
    int data;
    ListNode *next;

    ListNode(int data, ListNode *next = 0) : data(data), next(next) {}
};

struct LinkedList {
    ListNode *head = 0, *tail = 0;
    int elementCount = 0;

    bool Empty() {
        return !elementCount;
    }

    void addFirst(int value) {
        head = new ListNode(value, head);
        if (!tail)
            tail = head;
        elementCount++;
    }

    void addLast(int value) {
        if (!elementCount) {
            addFirst(value);
        } else {
            tail = tail->next = new ListNode(value);
            elementCount++;
        }
    }

    bool removeFirst() {
        if (!elementCount)
            return 0;

        ListNode *nextHead = head->next;
        delete head;
        head = nextHead;
        if (!head)
            tail = 0;
        elementCount--;
        return 1;
    }

    bool removeLast() {
        if (elementCount <= 1)
            return removeFirst();

        ListNode *prevTail = head;
        while (prevTail->next != tail)
            prevTail = prevTail->next;
        delete tail;
        tail = prevTail;
        elementCount--;
        return 1;
    }

    int size() {
        return elementCount;
    }

    void Print() {
        for (ListNode *n = head; n != tail; n = n->next)
            printf("%d ", n->data);
        printf("%d\n", tail->data);
    }
};