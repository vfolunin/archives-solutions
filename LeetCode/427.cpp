class Solution {
    Node *rec(vector<vector<int>> &a, int size, int y, int x) {
        if (size == 1)
            return new Node(a[y][x], 1);
        
        int half = size / 2;
        
        Node *res = new Node;
        
        res->topLeft = rec(a, half, y, x);
        res->topRight = rec(a, half, y, x + half);
        res->bottomLeft = rec(a, half, y + half, x);
        res->bottomRight = rec(a, half, y + half, x + half);
        
        if (res->topLeft->isLeaf && res->topRight->isLeaf &&
            res->bottomLeft->isLeaf && res->bottomRight->isLeaf &&
            res->topLeft->val == res->topRight->val &&
            res->topLeft->val == res->bottomLeft->val &&
            res->topLeft->val == res->bottomRight->val) {
            res->isLeaf = 1;
            res->val = res->topLeft->val;
            
            delete res->topLeft;
            delete res->topRight;
            delete res->bottomLeft;
            delete res->bottomRight;
            
            res->topLeft = res->topRight = res->bottomLeft = res->bottomRight = 0;
        }
        
        return res;
    }
    
public:
    Node *construct(vector<vector<int>> &a) {
        return rec(a, a.size(), 0, 0);
    }
};