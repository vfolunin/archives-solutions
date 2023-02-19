class Solution {
    void rec(TreeNode *n, vector<vector<int>> &graph, unordered_set<int> &leaves) {
        for (TreeNode *to : { n->left, n->right }) {
            if (to) {
                graph[n->val].push_back(to->val);
                graph[to->val].push_back(n->val);
                rec(to, graph, leaves);
            }
        }
        if (!n->left && !n->right)
            leaves.insert(n->val);
    }

    vector<int> bfs(vector<vector<int>> &graph, int start) {
        vector<int> dist(graph.size(), 1e9);
        queue<int> q;

        dist[start] = 0;
        q.push(start);

        while (!q.empty()) {
            int v = q.front();
            q.pop();

            for (int to : graph[v]) {
                if (dist[to] > dist[v] + 1) {
                    dist[to] = dist[v] + 1;
                    q.push(to);
                }
            }
        }

        return dist;
    }

public:
    int findClosestLeaf(TreeNode *root, int start) {
        vector<vector<int>> graph(1001);
        unordered_set<int> leaves;
        rec(root, graph, leaves);

        vector<int> dist = bfs(graph, start);

        int res = -1;
        for (int v : leaves)
            if (res == -1 || dist[res] > dist[v])
                res = v;
        return res;
    }
};