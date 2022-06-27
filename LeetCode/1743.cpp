class Solution {
public:
    vector<int> restoreArray(vector<vector<int>> &adjacentPairs) {
        unordered_map<int, vector<int>> graph;
        for (vector<int> &pair : adjacentPairs) {
            graph[pair[0]].push_back(pair[1]);
            graph[pair[1]].push_back(pair[0]);
        }
        
        int start;
        for (auto &[v, neighbors] : graph) {
            if (neighbors.size() == 1) {
                start = v;
                break;
            }
        }
        
        unordered_set<int> visited;
        vector<int> res;
        
        while (1) {
            visited.insert(start);
            res.push_back(start);
            
            if (!visited.count(graph[start][0]))
                start = graph[start][0];
            else if (graph[start].size() == 2)
                start = graph[start][1];
            else
                break;
        }
        
        return res;
    }
};