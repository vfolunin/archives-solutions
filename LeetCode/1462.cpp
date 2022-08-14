class Solution {
public:
    vector<bool> checkIfPrerequisite(int vertexCount, vector<vector<int>> &edges, vector<vector<int>> &queries) {
        vector<vector<int>> reachable(vertexCount, vector<int>(vertexCount));
        
        for (int v = 0; v < vertexCount; v++)
            reachable[v][v] = 1;
        
        for (vector<int> &edge : edges)
            reachable[edge[0]][edge[1]] = 1;
        
        for (int v = 0; v < vertexCount; v++)
            for (int a = 0; a < vertexCount; a++)
                for (int b = 0; b < vertexCount; b++)
                    reachable[a][b] |= reachable[a][v] && reachable[v][b];
        
        vector<bool> res(queries.size());
        for (int i = 0; i < res.size(); i++)
            res[i] = reachable[queries[i][0]][queries[i][1]];
        return res;
    }
};