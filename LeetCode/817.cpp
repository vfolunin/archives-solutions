class Solution {
    void dfs(unordered_map<int, vector<int>> &graph, int v, unordered_set<int> &visited) {
        visited.insert(v);
        for (int to : graph[v])
            if (!visited.count(to))
                dfs(graph, to, visited);
    }
    
public:
    int numComponents(ListNode *head, vector<int> &a) {
        unordered_map<int, vector<int>> graph;
        for (ListNode *n = head; n->next; n = n->next) {
            graph[n->val].push_back(n->next->val);
            graph[n->next->val].push_back(n->val);
        }
        
        unordered_set<int> visited;
        for (ListNode *n = head; n; n = n->next)
            visited.insert(n->val);
        for (int v : a)
            visited.erase(v);
        
        int res = 0;
        for (int v : a) {
            if (!visited.count(v)) {
                dfs(graph, v, visited);
                res++;
            }
        }
        return res;
    }
};