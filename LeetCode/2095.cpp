class Solution {    
public:
    ListNode *deleteMiddle(ListNode *head) {
        if (!head->next)
            return 0;
        
        ListNode *slow = head, *fast = head->next;
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        slow->next = slow->next->next;
        
        return head;
    }
};