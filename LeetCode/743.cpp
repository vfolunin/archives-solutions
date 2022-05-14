class Solution {
public:
    int networkDelayTime(vector<vector<int>> &edges, int vertexCount, int start) {
        vector<int> dist(vertexCount, 1e9);
        dist[start - 1] = 0;
        
        for (int i = 0; i < vertexCount - 1; i++)
            for (vector<int> &edge : edges)
                dist[edge[1] - 1] = min(dist[edge[1] - 1], dist[edge[0] - 1] + edge[2]);
        
        int res = *max_element(dist.begin(), dist.end());
        return res != 1e9 ? res : -1;
    }
};