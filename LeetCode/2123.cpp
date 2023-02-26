class Solution {
    bool dfs(vector<vector<int>> &graphA, int vFromA, vector<int> &visited, int iteration, vector<int> &pairFromA) {
        visited[vFromA] = iteration;

        for (int vFromB : graphA[vFromA]) {
            int &toFromA = pairFromA[vFromB];

            if (toFromA == -1 || visited[toFromA] != iteration && dfs(graphA, toFromA, visited, iteration, pairFromA)) {
                toFromA = vFromA;
                return 1;
            }
        }

        return 0;
    }

    vector<int> kuhn(vector<vector<int>> &graphA, int vertexCountB) {
        vector<int> pairFromA(vertexCountB, -1);
        vector<int> visited(graphA.size(), -1);

        for (int vFromA = 0; vFromA < graphA.size(); vFromA++) {
            dfs(graphA, vFromA, visited, vFromA, pairFromA);
        }

        return pairFromA;
    }

public:
    int minimumOperations(vector<vector<int>> &a) {
        int h = a.size(), w = a[0].size();
        int vertexCountA = h * w / 2, vertexCountB = h * w - vertexCountA;

        vector<vector<int>> graphA(vertexCountA);
        vector<int> dy = { -1, 0, 1, 0 };
        vector<int> dx = { 0, 1, 0, -1 };

        for (int y = 0; y < h; y++) {
            for (int x = 0; x < w; x++) {
                if ((y + x) % 2 == 0 || !a[y][x])
                    continue;

                for (int d = 0; d < dy.size(); d++) {
                    int ty = y + dy[d];
                    int tx = x + dx[d];

                    if (0 <= ty && ty < h && 0 <= tx && tx < w && a[ty][tx])
                        graphA[(y * w + x) / 2].push_back((ty * w + tx) / 2);
                }
            }
        }

        int matchingSize = 0;
        for (int vFromA : kuhn(graphA, vertexCountB))
            matchingSize += vFromA != -1;
        return matchingSize;
    }
};