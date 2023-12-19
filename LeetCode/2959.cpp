class Solution {
    bool check(int vertexCount, int limit, vector<vector<int>> &edges, int mask) {
        vector<vector<int>> dist(vertexCount, vector<int>(vertexCount, 1e9));
        for (int v = 0; v < vertexCount; v++)
            dist[v][v] = 0;

        for (vector<int> &edge : edges) {
            int a = edge[0], b = edge[1], w = edge[2];
            if ((mask & (1 << a)) && (mask & (1 << b)))
                dist[a][b] = dist[b][a] = min(dist[a][b], w);
        }

        for (int v = 0; v < vertexCount; v++)
            for (int a = 0; a < vertexCount; a++)
                for (int b = 0; b < vertexCount; b++)
                    dist[a][b] = min(dist[a][b], dist[a][v] + dist[v][b]);

        for (int a = 0; a < vertexCount; a++)
            for (int b = 0; b < vertexCount; b++)
                if ((mask & (1 << a)) && (mask & (1 << b)) && dist[a][b] > limit)
                    return 0;
        return 1;
    }

public:
    int numberOfSets(int vertexCount, int limit, vector<vector<int>> &edges) {
        int res = 0;
        for (int mask = 0; mask < (1 << vertexCount); mask++)
            res += check(vertexCount, limit, edges, mask);
        return res;
    }
};