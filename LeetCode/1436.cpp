class Solution {
public:
    string destCity(vector<vector<string>> &edges) {
        unordered_set<string> cities, sources;
        
        for (vector<string> &edge : edges) {
            cities.insert(edge[0]);
            cities.insert(edge[1]);
            sources.insert(edge[0]);
        }
        
        for (const string &v : cities)
            if (!sources.count(v))
                return v;
        
        return "";
    }
};