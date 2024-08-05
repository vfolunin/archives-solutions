class Solution {
public:
    vector<int> shortestDistanceAfterQueries(int vertexCount, vector<vector<int>> &queries) {
        set<int> vertices;
        for (int v = 0; v < vertexCount; v++)
            vertices.insert(v);

        vector<int> res;
        for (vector<int> &query : queries) {
            if (vertices.count(query[0]) && vertices.count(query[1])) 
                for (auto it = next(vertices.find(query[0])); *it != query[1]; it = vertices.erase(it));
            
            res.push_back(vertices.size() - 1);
        }
        return res;
    }
};