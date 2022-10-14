class Solution {
    vector<string> euler(unordered_map<string, multiset<string>> &graph) {
        vector<string> stack = { "JFK" }, path;
        while (!stack.empty()) {
            string v = stack.back();
            if (!graph[v].empty()) {
                string to = *graph[v].begin();
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
    vector<string> findItinerary(vector<vector<string>> &edges) {
        unordered_map<string, multiset<string>> graph;
        for (vector<string> &edge : edges)
            graph[edge[0]].insert(edge[1]);
        
        return euler(graph);
    }
};