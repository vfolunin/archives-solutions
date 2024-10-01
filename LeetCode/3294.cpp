class Solution {
public:
	vector<int> toArray(Node *n) {
        while (n->prev)
            n = n->prev;
        
        vector<int> res;
        for ( ; n; n = n->next)
            res.push_back(n->val);
        return res;
    }
};