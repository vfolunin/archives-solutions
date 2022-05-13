class Solution {
    vector<Node *> stack;
    
public:
    Node *connect(Node *n, int depth = 0) {
        if (!n)
            return n;
        
        if (depth == stack.size())
            stack.emplace_back();
        
        n->next = stack[depth];
        
        connect(n->right, depth + 1);
        connect(n->left, depth + 1);
        
        stack[depth] = n;
        return n;
    }
};