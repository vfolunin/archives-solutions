class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *fast = head, *slow = head;
        
        do {
            if (!fast || !fast->next || !fast->next->next)
                return 0;
            fast = fast->next->next;
            slow = slow->next;
        } while (fast != slow);
        
        fast = head;
        
        while (fast != slow) {
            fast = fast->next;
            slow = slow->next;
        }
        
        return fast;
    }
};