class Solution {
public:
	vector<int> toArray(Node *head){
        vector<int> res;
        for (Node *n = head; n; n = n->next)
            res.push_back(n->val);
        return res;
    }
};