class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *fast = head, *slow = head;
        
        while (1) {
            if (!fast || !fast->next || !fast->next->next)
                return 0;
            
            fast = fast->next->next;
            slow = slow->next;
            
            if (fast == slow)
                return 1;
        }
    }
};