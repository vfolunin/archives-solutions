class Solution {
public:
    vector<int> countOfPairs(int vertexCount, int x, int y) {
        vector<vector<int>> dist(vertexCount, vector<int>(vertexCount, 1e9));
        for (int v = 0; v < vertexCount; v++) {
            dist[v][v] = 0;
            if (v)
                dist[v - 1][v] = dist[v][v - 1] = 1;
        }
        x--;
        y--;
        dist[x][y] = dist[y][x] = min(dist[x][y], 1);

        for (int v = 0; v < vertexCount; v++)
            for (int a = 0; a < vertexCount; a++)
                for (int b = 0; b < vertexCount; b++)
                    dist[a][b] = min(dist[a][b], dist[a][v] + dist[v][b]);

        vector<int> res(vertexCount);
        for (int a = 0; a < vertexCount; a++)
            for (int b = 0; b < vertexCount; b++)
                if (a != b)
                    res[dist[a][b] - 1]++;
        return res;
    }
};