class Solution {
    void dfs(vector<vector<int>> &graph, int v, vector<int> &visited, bool &hasCycle) {
        visited[v] = 1;
        for (int to : graph[v]) {
            if (visited[to] == 0)
                dfs(graph, to, visited, hasCycle);
            else if (visited[to] == 1)
                hasCycle = 1;
        }
        visited[v] = 2;
    }
    
public:
    bool validateBinaryTreeNodes(int vertexCount, vector<int> &left, vector<int> &right) {
        vector<vector<int>> graph(vertexCount);
        vector<int> inDegree(vertexCount);
        
        for (int v = 0; v < vertexCount; v++) {
            if (left[v] != -1) {
                graph[v].push_back(left[v]);
                inDegree[left[v]]++;                
            }
            if (right[v] != -1) {
                graph[v].push_back(right[v]);
                inDegree[right[v]]++;                
            }
        }
        
        if (*max_element(inDegree.begin(), inDegree.end()) > 1 ||
            count(inDegree.begin(), inDegree.end(), 0) != 1)
            return 0;
        
        int root = find(inDegree.begin(), inDegree.end(), 0) - inDegree.begin();
        vector<int> visited(vertexCount);
        bool hasCycle = 0;
        dfs(graph, root, visited, hasCycle);
        
        return !hasCycle && !count(visited.begin(), visited.end(), 0);
    }
};