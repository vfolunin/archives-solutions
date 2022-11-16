class Solution {
public:
    int checkWays(vector<vector<int>> &pairs) {
        unordered_map<int, unordered_set<int>> pairsOf;
        for (vector<int> &pair : pairs) {
            pairsOf[pair[0]].insert(pair[1]);
            pairsOf[pair[1]].insert(pair[0]);
        }
        
        int vertexCount = pairsOf.size();
        
        priority_queue<pair<int, int>> q;
        for (auto &[v, pairs] : pairsOf)
            q.push({ pairs.size(), v });
        
        unordered_set<int> visited;
        bool multiple = 0;
        
        while (!q.empty()) {
            auto [pairCount, v] = q.top();
            q.pop();
            
            visited.insert(v);
            
            int parent = -1;
            for (int to : pairsOf[v])
                if (visited.count(to) && (parent == -1 || pairsOf[parent].size() > pairsOf[to].size()))
                    parent = to;
            
            if (parent == -1) {
                if (pairCount != vertexCount - 1)
                    return 0;
            } else {
                for (auto to : pairsOf[v])
                    if (to != parent && !pairsOf[parent].count(to))
                        return 0;
            }
            
            multiple |= pairCount == pairsOf[parent].size();
        }

        return 1 + multiple;
    }
};