class Solution {
public:
    vector<vector<int>> levelOrder(Node *root) {
        vector<vector<int>> res;
        queue<Node *> q;
        
        if (root)
            q.push(root);
        
        while (!q.empty()) {
            res.emplace_back(q.size());
            
            for (int &value : res.back()) {
                Node *v = q.front();
                q.pop();

                value = v->val;

                for (Node *to : v->children)
                    q.push(to);
            }
        }
        
        return res;
    }
};