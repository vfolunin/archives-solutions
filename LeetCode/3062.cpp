class Solution {
public:
    string gameResult(ListNode *head) {
        vector<int> score(2);
        for (ListNode *n = head; n; n = n->next->next)
            score[n->val < n->next->val]++;
        
        if (score[0] < score[1])
            return "Odd";
        else if (score[0] == score[1])
            return "Tie";
        else
            return "Even";
    }
};