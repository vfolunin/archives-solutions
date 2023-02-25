class Solution {
    bool dfs(vector<vector<int>> &graphA, int vFromA, vector<int> &visited, vector<int> &pairFromA) {
        visited[vFromA] = 1;

        for (int vFromB : graphA[vFromA]) {
            int &toFromA = pairFromA[vFromB];

            if (toFromA == -1 || !visited[toFromA] && dfs(graphA, toFromA, visited, pairFromA)) {
                toFromA = vFromA;
                return 1;
            }
        }

        return 0;
    }

    vector<int> kuhn(vector<vector<int>> &graphA, int vertexCountB) {
        vector<int> pairFromA(vertexCountB, -1);

        for (int vFromA = 0; vFromA < graphA.size(); vFromA++) {
            vector<int> visited(graphA.size());
            dfs(graphA, vFromA, visited, pairFromA);
        }

        return pairFromA;
    }

public:
    int maximumInvitations(vector<vector<int>> &hasEdge) {
        int vertexCountA = hasEdge.size(), vertexCountB = hasEdge[0].size();

        vector<vector<int>> graphA(vertexCountA);
        for (int a = 0; a < vertexCountA; a++)
            for (int b = 0; b < vertexCountB; b++)
                if (hasEdge[a][b])
                    graphA[a].push_back(b);
        
        int matchingSize = 0;
        for (int vFromA : kuhn(graphA, vertexCountB))
            matchingSize += vFromA != -1;
        return matchingSize;
    }
};