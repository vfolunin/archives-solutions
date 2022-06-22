class Solution {
public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        set<pair<int, int>> q;
        for (int i = 0; i < lists.size(); i++)
            if (lists[i])
                q.insert({ lists[i]->val, i });
        
        ListNode head(0), *n = &head;
        
        while (!q.empty()) {
            int i = q.begin()->second;
            q.erase({ lists[i]->val, i });
            
            n = n->next = lists[i];
            lists[i] = lists[i]->next;
            
            if (lists[i])
                q.insert({ lists[i]->val, i });
        }
        
        return head.next;
    }
};