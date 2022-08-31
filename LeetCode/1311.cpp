class Solution {
    vector<int> bfs(vector<vector<int>> &graph, int start) {
        vector<int> dist(graph.size(), 1e9);
        queue<int> q;

        dist[start] = 0;
        q.push(start);

        while (!q.empty()) {
            int v = q.front();
            q.pop();

            for (int to : graph[v]) {
                if (dist[to] > dist[v] + 1) {
                    dist[to] = dist[v] + 1;
                    q.push(to);
                }
            }
        }

        return dist;
    }
    
public:
    vector<string> watchedVideosByFriends(vector<vector<string>> &videos,
                                          vector<vector<int>> &graph, int start, int targetDist) {
        vector<int> dist = bfs(graph, start);
        
        unordered_map<string, int> count;
        for (int v = 0; v < graph.size(); v++)
            if (dist[v] == targetDist)
                for (string &video : videos[v])
                    count[video]++;
        
        vector<pair<string, int>> pairs(count.begin(), count.end());
        sort(pairs.begin(), pairs.end(), [](auto &a, auto &b) {
            if (a.second != b.second)
                return a.second < b.second;
            return a.first < b.first;
        });
        
        vector<string> res(pairs.size());
        for (int i = 0; i < res.size(); i++)
            res[i] = pairs[i].first;
        return res;
    }
};