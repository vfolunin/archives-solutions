class Solution {
public:
    vector<int> countPairs(int vertexCount, vector<vector<int>> &edges, vector<int> &queries) {
        vector<int> degree(vertexCount);
        for (vector<int> &edge : edges) {
            edge[0]--;
            edge[1]--;           
            degree[edge[0]]++;
            degree[edge[1]]++;
        }
        
        unordered_map<int, int> degreeCount;
        for (int v = 0; v < vertexCount; v++)
            degreeCount[degree[v]]++;
        
        unordered_map<int, int> incidentCount;
        for (auto &[degreeA, countA] : degreeCount) {
            incidentCount[degreeA * 2] += countA * (countA - 1) / 2;
            for (auto &[degreeB, countB] : degreeCount)
                if (degreeA < degreeB)
                    incidentCount[degreeA + degreeB] += countA * countB;
        }
        
        map<pair<int, int>, int> edgeCount;
        for (vector<int> &edge : edges) {
            if (edge[0] > edge[1])
                swap(edge[0], edge[1]);
            edgeCount[{ edge[0], edge[1] }]++;
        }
        
        for (auto &[edge, count] : edgeCount) {
            auto [a, b] = edge;
            incidentCount[degree[a] + degree[b]]--;
            incidentCount[degree[a] + degree[b] - count]++;
        }
        
        vector<int> resCount;
        for (auto &[degreeSum, count] : incidentCount) {
            if (resCount.size() <= degreeSum)
                resCount.resize(degreeSum + 1);
            resCount[degreeSum] = count;
        }
        for (int i = resCount.size() - 2; i >= 0; i--)
            resCount[i] += resCount[i + 1];
        
        vector<int> res(queries.size());
        for (int i = 0; i < queries.size(); i++)
            if (queries[i] + 1 < resCount.size()) 
                res[i] = resCount[queries[i] + 1];
        return res;
    }
};