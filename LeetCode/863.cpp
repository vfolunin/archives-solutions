class Solution {
    void makeGraph(TreeNode *n, unordered_map<TreeNode *, vector<TreeNode *>> &graph) {
        if (!n)
            return;
        
        if (n->left) {
            graph[n].push_back(n->left);
            graph[n->left].push_back(n);
            makeGraph(n->left, graph);
        }
        if (n->right) {
            graph[n].push_back(n->right);
            graph[n->right].push_back(n);
            makeGraph(n->right, graph);
        }
    }
    
    void rec(unordered_map<TreeNode *, vector<TreeNode *>> &graph, TreeNode *v, TreeNode *p,
             int depth, int targetDepth, vector<int> &res) {
        if (depth == targetDepth)
            res.push_back(v->val);
        
        for (TreeNode *to : graph[v])
            if (to != p)
                rec(graph, to, v, depth + 1, targetDepth, res);
    }
    
public:
    vector<int> distanceK(TreeNode *root, TreeNode *target, int k) {
        unordered_map<TreeNode *, vector<TreeNode *>> graph;
        makeGraph(root, graph);
        
        vector<int> res;
        rec(graph, target, 0, 0, k, res);
        return res;
    }
};