class Solution {
public:
    Node *cloneGraph(Node *node) {
        if (!node)
            return 0;
        
        static unordered_map<Node *, Node *> memo;
        if (auto it = memo.find(node); it != memo.end())
            return it->second;
        Node *&res = memo[node];
        
        res = new Node(node->val);
        for (Node *to : node->neighbors)
            res->neighbors.push_back(cloneGraph(to));
        
        return res;
    }
};