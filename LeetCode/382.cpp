class Solution {
    vector<int> a;
    
public:
    Solution(ListNode *head) {
        for ( ; head; head = head->next)
            a.push_back(head->val);
    }
    
    int getRandom() {
        return a[rand() % a.size()];
    }
};