class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode *head) {
        int first = -1, last = -1;
        int minDist = -1, maxDist = -1;
        ListNode *a = head, *b = a->next, *c = b->next;
        
        for (int i = 1; c; i++) {
            if (a->val < b->val && b->val > c->val || a->val > b->val && b->val < c->val) {
                if (first != -1 && maxDist < i - first)
                    maxDist = i - first;
                if (last != -1 && (minDist == -1 || minDist > i - last))
                    minDist = i - last;
                
                if (first == -1)
                    first = i;
                last = i;
            }
            
            a = b;
            b = c;
            c = c->next;
        }
        
        return { minDist, maxDist };
    }
};