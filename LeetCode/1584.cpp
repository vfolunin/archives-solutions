class Solution {
    int weight(vector<vector<int>> &points, int a, int b) {
        return abs(points[a][0] - points[b][0]) + abs(points[a][1] - points[b][1]);
    }
    
public:
    int minCostConnectPoints(vector<vector<int>> &points) {
        vector<int> visited(points.size());
        vector<int> dist(points.size(), 1e9);
        dist[0] = 0;
        
        int mstWeight = 0;
        
        for (int i = 0; i < points.size(); i++) {
            int v = -1;
            for (int j = 0; j < points.size(); j++)
                if (!visited[j] && (v == -1 || dist[v] > dist[j]))
                    v = j;
            
            visited[v] = 1;
            mstWeight += dist[v];
            
            for (int to = 0; to < points.size(); to++)
                dist[to] = min(dist[to], weight(points, v, to));
        }
        
        return mstWeight;
    }
};