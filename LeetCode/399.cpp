class Solution {
    struct Compressor {
        unordered_map<string, int> s2i;
        
        void add(const string &s) {
            if (!s2i.count(s))
                s2i[s] = s2i.size();
        }
        
        int get(const string &s) {
            return s2i.count(s) ? s2i[s] : -1;
        }
        
        int size() {
            return s2i.size();
        }
    };
    
public:
    vector<double> calcEquation(vector<vector<string>> &equations, vector<double> &values, vector<vector<string>> &queries) {
        Compressor compressor;
        for (vector<string> &equation : equations) {
            compressor.add(equation[0]);
            compressor.add(equation[1]);
        }
        
        int vertexCount = compressor.size();
        vector<vector<double>> dist(vertexCount, vector<double>(vertexCount));
        for (int v = 0; v < vertexCount; v++)
            dist[v][v] = 1;
        
        for (int i = 0; i < equations.size(); i++) {
            int a = compressor.get(equations[i][0]), b = compressor.get(equations[i][1]);
            dist[a][b] = values[i];
            dist[b][a] = 1 / values[i];
        }
        
        for (int v = 0; v < vertexCount; v++)
            for (int a = 0; a < vertexCount; a++)
                for (int b = 0; b < vertexCount; b++)
                    if (dist[a][v] && dist[v][b])
                        dist[a][b] = dist[a][v] * dist[v][b];
        
        vector<double> res;
        for (vector<string> &query : queries) {
            int a = compressor.get(query[0]), b = compressor.get(query[1]);
            res.push_back(a != -1 && b != -1 && dist[a][b] ? dist[a][b] : -1);
        }
        return res;
    }
};