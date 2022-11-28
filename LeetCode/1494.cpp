class Solution {
    int rec(int mask, vector<vector<int>> &graph, vector<int> &inDegree, int k, vector<int> &memo) {
        int &res = memo[mask];
        if (res != -1)
            return res;
        
        if (!mask)
            return res = 0;
        
        vector<int> bits;
        for (int bit = 0; bit < graph.size(); bit++)
            if ((mask & (1 << bit)) && !inDegree[bit])
                bits.push_back(bit);
        
        string bitMask(bits.size(), 0);
        fill(max(bitMask.begin(), bitMask.end() - k), bitMask.end(), 1);
        res = 1e9;
        
        do {
            for (int i = 0; i < bitMask.size(); i++) {
                if (bitMask[i]) {
                    mask ^= 1 << bits[i];
                    for (int to : graph[bits[i]])
                        inDegree[to]--;
                }
            }

            res = min(res, 1 + rec(mask, graph, inDegree, k, memo));

            for (int i = 0; i < bitMask.size(); i++) {
                if (bitMask[i]) {
                    mask ^= 1 << bits[i];
                    for (int to : graph[bits[i]])
                        inDegree[to]++;
                }
            }
        } while (next_permutation(bitMask.begin(), bitMask.end()));

        return res;
    }
    
public:
    int minNumberOfSemesters(int vertexCount, vector<vector<int>> &edges, int k) {
        vector<vector<int>> graph(vertexCount);
        vector<int> inDegree(vertexCount);
        for (vector<int> &edge : edges) {
            graph[edge[0] - 1].push_back(edge[1] - 1);
            inDegree[edge[1] - 1]++;
        }
        
        vector<int> memo(1 << vertexCount, -1);
        return rec((1 << vertexCount) - 1, graph, inDegree, k, memo);
    }
};