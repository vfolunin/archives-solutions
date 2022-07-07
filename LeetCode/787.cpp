class Solution {
public:
    int findCheapestPrice(int vertexCount, vector<vector<int>> &edges, int start, int finish, int k) {
        const int INF = 1e9;
        vector<vector<int>> dist(2, vector<int>(vertexCount, INF));
        dist[0][start] = 0;
        
        for (int i = 0; i <= k; i++) {
            for (vector<int> &edge : edges)
                if (dist[0][edge[0]] != INF && dist[1][edge[1]] > dist[0][edge[0]] + edge[2])
                    dist[1][edge[1]] = dist[0][edge[0]] + edge[2];
            dist[0] = dist[1];
        }
        
        return dist[0][finish] != INF ? dist[0][finish] : -1;
    }
};