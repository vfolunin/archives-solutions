class Solution {
    using Graph = unordered_map<TreeNode *, unordered_set<TreeNode *>>;

    void constructGraph(TreeNode *node, TreeNode *parent, Graph &graph) {
        if (!node)
            return;

        graph[node];
        for (TreeNode *to : { parent, node->left, node->right })
            if (to)
                graph[node].insert(to);
        
        constructGraph(node->left, node, graph);
        constructGraph(node->right, node, graph);
    }

    void rec(Graph &graph, TreeNode *node, unordered_set<int> &values, int sum, int &res) {
        values.insert(node->val);
        sum += node->val;
        res = max(res, sum);

        for (TreeNode *to : graph[node])
            if (!values.contains(to->val))
                rec(graph, to, values, sum, res);

        values.erase(node->val);
        sum -= node->val;
    }

public:
    int maxSum(TreeNode *root) {
        Graph graph;
        constructGraph(root, 0, graph);

        unordered_set<int> values;
        int res = -2e9;
        for (auto &[node, _] : graph)
            rec(graph, node, values, 0, res);
        return res;
    }
};