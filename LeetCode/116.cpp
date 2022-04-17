class Solution {
    vector<Node *> stack;
    
public:
    Node *connect(Node *n, int depth = 0) {
        if (!n)
            return n;
        
        if (stack.size() == depth)
            stack.emplace_back();
        if (stack[depth])
            stack[depth]->next = n;
        stack[depth] = n;
        
        connect(n->left, depth + 1);
        connect(n->right, depth + 1);
        
        return n;
    }
};