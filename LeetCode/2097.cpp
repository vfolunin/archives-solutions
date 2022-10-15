class Solution {
    vector<int> euler(unordered_map<int, unordered_multiset<int>> &graph, int start) {
        vector<int> stack = { start }, path;        
        while (!stack.empty()) {
            int v = stack.back();            
            if (!graph[v].empty()) {
                int to = *graph[v].begin();
                graph[v].erase(graph[v].find(to));
                stack.push_back(to);
            } else {
                stack.pop_back();
                path.push_back(v);
            }
        }
        reverse(path.begin(), path.end());
        return path;
    }
    
public:
    vector<vector<int>> validArrangement(vector<vector<int>> &edges) {
        unordered_map<int, unordered_multiset<int>> graph;
        unordered_map<int, int> inDegree;
        for (vector<int> &edge : edges) {
            graph[edge[0]].insert(edge[1]);
            inDegree[edge[1]]++;
        }
        
        int start = graph.begin()->first;
        for (auto &[v, edges] : graph) {
            if (inDegree[v] < edges.size()) {
                start = v;
                break;
            }
        }
        
        vector<int> path = euler(graph, start);
        
        vector<vector<int>> res;
        for (int i = 0; i + 1 < path.size(); i++)
            res.push_back({ path[i], path[i + 1] });
        return res;
    }
};