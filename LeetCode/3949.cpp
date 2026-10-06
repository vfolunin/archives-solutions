class Solution {
    vector<int> &rec(vector<vector<int>> &graph, int v, int parent, int sign,
                     vector<int> &a, int distThreshold, vector<vector<vector<int>>> &memo) {
        vector<int> &res = memo[v][sign + 1];
        if (!res.empty())
            return res;

        res.assign(distThreshold + 1, -1e9);
        res[distThreshold] = sign * a[v];

        for (int to : graph[v]) {
            if (to == parent)
                continue;

            vector<int> &toRes = rec(graph, to, v, sign, a, distThreshold, memo);

            vector<int> rMaxRes = res;
            vector<int> toRMaxRes = toRes;
            for (int dist = distThreshold - 1; dist >= 0; dist--) {
                rMaxRes[dist] = max(rMaxRes[dist], rMaxRes[dist + 1]);
                toRMaxRes[dist] = max(toRMaxRes[dist], toRMaxRes[dist + 1]);
            }

            vector<int> nextRes(distThreshold + 1, -1e9);
            for (int vDist = 0; vDist <= distThreshold; vDist++) {
                int needToDist = max({ vDist - 1, distThreshold - vDist - 1, 0 });
                if (res[vDist] != -1e9 && toRMaxRes[needToDist] != -1e9)
                    nextRes[vDist] = max(nextRes[vDist], res[vDist] + toRMaxRes[needToDist]);
            }

            for (int toDist = 0; toDist <= distThreshold; toDist++) {
                int vDist = min(toDist + 1, distThreshold);
                int needVDist = max(vDist, distThreshold - vDist);
                if (toRes[toDist] != -1e9 && rMaxRes[needVDist] != -1e9)
                    nextRes[vDist] = max(nextRes[vDist], toRes[toDist] + rMaxRes[needVDist]);
            }

            res.swap(nextRes);
        }

        res[0] = -sign * a[v];

        for (int to : graph[v]) {
            if (to == parent)
                continue;

            vector<int> &toInvertedRes = rec(graph, to, v, -sign, a, distThreshold, memo);
            res[0] += max(toInvertedRes[distThreshold - 1], toInvertedRes[distThreshold]);
        }

        return res;
    }

public:
    int subtreeInversionSum(vector<vector<int>> &edges, vector<int> &a, int distThreshold) {
        vector<vector<int>> graph(a.size());
        for (vector<int> &edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        vector memo(graph.size(), vector<vector<int>>(3));
        vector<int> &res = rec(graph, 0, -1, 1, a, distThreshold, memo);
        return *max_element(res.begin(), res.end());
    }
};