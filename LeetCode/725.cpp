class Solution {
    int getLength(ListNode *n) {
        int res = 0;
        for ( ; n; n = n->next)
            res++;
        return res;
    }
    
    ListNode *advance(ListNode *n, int k) {
        for (int i = 0; i < k; i++)
            n = n->next;
        return n;
    }
    
    ListNode *getPart(ListNode *&n, int k) {
        if (!n)
            return 0;
        ListNode *prevN = n;
        n = advance(n, k - 1);
        ListNode *nextN = n->next;
        n->next = 0;
        n = nextN;
        return prevN;
    }
    
public:
    vector<ListNode *> splitListToParts(ListNode *head, int partCount) {
        int len = getLength(head);
        int smallPartSize = len / partCount, bigPartSize = smallPartSize + 1;
        int smallPartCount = partCount - len % partCount, bigPartCount = partCount - smallPartCount;
        
        vector<ListNode *> parts(partCount);
        for (int i = 0; i < bigPartCount; i++)
            parts[i] = getPart(head, bigPartSize);
        for (int i = bigPartCount; i < partCount; i++)
            parts[i] = getPart(head, smallPartSize);
        return parts;
    }
};