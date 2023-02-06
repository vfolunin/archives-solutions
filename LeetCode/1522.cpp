class Solution {
    int rec(Node *n, int &res) {
        if (n->children.empty())
            return 0;

        vector<int> paths = { 0 };
        for (Node *child : n->children)
            paths.push_back(rec(child, res) + 1);
        
        sort(paths.rbegin(), paths.rend());
        res = max(res, paths[0] + paths[1]);        
        return paths[0];
    }

public:
    int diameter(Node *root) {
        int res = 0;
        rec(root, res);
        return res;
    }
};