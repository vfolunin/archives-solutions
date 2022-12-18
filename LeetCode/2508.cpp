class Solution {
public:
    bool isPossible(int vertexCount, vector<vector<int>> &edges) {
        vector<int> degree(vertexCount);
        set<pair<int, int>> edgeSet;
        for (vector<int> &edge : edges) {
            edge[0]--;
            edge[1]--;
            degree[edge[0]]++;
            degree[edge[1]]++;
            edgeSet.insert({ edge[0], edge[1] });
            edgeSet.insert({ edge[1], edge[0] });
        }

        vector<int> odd;
        for (int v = 0; v < vertexCount; v++)
            if (degree[v] % 2)
                odd.push_back(v);
        
        if (odd.empty())
            return 1;
        if (odd.size() % 2 || odd.size() > 4)
            return 0;

        if (odd.size() == 4) {
            do {
                if (!edgeSet.count({ odd[0], odd[1] }) && !edgeSet.count({ odd[2], odd[3] }))
                    return 1;
            } while (next_permutation(odd.begin(), odd.end()));
            return 0;
        }
        
        if (!edgeSet.count({ odd[0], odd[1] }))
            return 1;

        for (int v = 0; v < vertexCount; v++)
            if (v != odd[0] && v != odd[1] && !edgeSet.count({ v, odd[0] }) && !edgeSet.count({ v, odd[1] }))
                return 1;
        return 0;
    }
};