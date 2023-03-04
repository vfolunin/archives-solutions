class Solution {
    void dfs(vector<vector<int>> &graph, int v, int p, set<vector<int>> &guessSet,
             int &forwardEdgeCount, vector<int> &forwardCount, vector<int> &reverseCount) {        
        for (int to : graph[v]) {
            if (to == p)
                continue;
            
            forwardEdgeCount += guessSet.count({ v, to });
            forwardCount[to] = forwardCount[v] + guessSet.count({ v, to });
            reverseCount[to] = reverseCount[v] + guessSet.count({ to, v });
            dfs(graph, to, v, guessSet, forwardEdgeCount, forwardCount, reverseCount);
        }
    }
    
public:
    int rootCount(vector<vector<int>> &edges, vector<vector<int>> &guesses, int k) {
        vector<vector<int>> graph(edges.size() + 1);
        for (vector<int> &edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        
        set<vector<int>> guessSet(guesses.begin(), guesses.end());
        int forwardEdgeCount = 0;
        vector<int> forwardCount(graph.size());
        vector<int> reverseCount(graph.size());        
        dfs(graph, 0, -1, guessSet, forwardEdgeCount, forwardCount, reverseCount);
        
        int res = 0;
        for (int v = 0; v < graph.size(); v++)
            res += forwardEdgeCount - forwardCount[v] + reverseCount[v] >= k;        
        return res;
    }
};