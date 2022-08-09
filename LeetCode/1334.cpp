class Solution {
public:
    int findTheCity(int vertexCount, vector<vector<int>> &edges, int distLimit) {
        vector<vector<int>> dist(vertexCount, vector<int>(vertexCount, 1e9));
        
        for (int v = 0; v < vertexCount; v++)
            dist[v][v] = 0;
        
        for (vector<int> &edge : edges)
            dist[edge[0]][edge[1]] = dist[edge[1]][edge[0]] = min(dist[edge[0]][edge[1]], edge[2]);
        
        for (int v = 0; v < vertexCount; v++)
            for (int a = 0; a < vertexCount; a++)
                for (int b = 0; b < vertexCount; b++)
                    dist[a][b] = min(dist[a][b], dist[a][v] + dist[v][b]);
        
        int res, resCount;
        for (int v = 0; v < vertexCount; v++) {
            int count = 0;
            for (int to = 0; to < vertexCount; to++)
                count += dist[v][to] <= distLimit;
            
            if (!v || resCount >= count) {
                res = v;
                resCount = count;
            }
        }
        return res;
    }
};