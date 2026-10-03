class Solution {
    long long dfs1(vector<vector<int>> &graph, int v, int parent, vector<int> &baseTime,
                   vector<long long> &time) {
        int childCount = 0;
        long long minTime = 1e18, maxTime = -1e18;

        for (int to : graph[v]) {
            if (to == parent)
                continue;

            childCount++;
            long long childTime = dfs1(graph, to, v, baseTime, time);
            minTime = min(minTime, childTime);
            maxTime = max(maxTime, childTime);
        }

        return time[v] = baseTime[v] + (childCount ? 2 * maxTime - minTime : 0);
    }

    long long dfs2(vector<vector<int>> &graph, int v, int parent, vector<int> &baseTime,
                   vector<long long> &time, long long parentTime) {
        int childCount = graph[v].size();
        long long minTime1 = 1e18, minTime2 = 1e18, maxTime1 = -1e18, maxTime2 = -1e18;
        int minChild = -1, maxChild = -1;

        for (int to : graph[v]) {
            long long childTime = to == parent ? parentTime : time[to];

            if (minTime1 > childTime) {
                minTime2 = minTime1;
                minTime1 = childTime;
                minChild = to;
            } else if (minTime2 > childTime) {
                minTime2 = childTime;
            }

            if (maxTime1 < childTime) {
                maxTime2 = maxTime1;
                maxTime1 = childTime;
                maxChild = to;
            } else if (maxTime2 < childTime) {
                maxTime2 = childTime;
            }
        }

        long long res = baseTime[v] + (childCount ? 2 * maxTime1 - minTime1 : 0);
        for (int to : graph[v]) {
            if (to == parent)
                continue;

            long long minTime = to == minChild ? minTime2 : minTime1;
            long long maxTime = to == maxChild ? maxTime2 : maxTime1;
            long long nextParentTime = baseTime[v] + (childCount > 1 ? 2 * maxTime - minTime : 0);
            res = min(res, dfs2(graph, to, v, baseTime, time, nextParentTime));
        }
        return res;
    }

public:
    long long finishTime(int vertexCount, vector<vector<int>> &edges, vector<int> &baseTime) {
        vector<vector<int>> graph(vertexCount);
        for (vector<int> &edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        vector<long long> time(vertexCount);
        dfs1(graph, 0, -1, baseTime, time);
        return dfs2(graph, 0, -1, baseTime, time, 0);
    }
};