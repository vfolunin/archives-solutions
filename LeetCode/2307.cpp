class Solution {
    bool dfs(unordered_map<string, set<pair<string, double>>> &graph, const string &v, unordered_map<string, double> &value) {
        for (auto &[to, factor] : graph[v]) {
            if (!value.count(to)) {
                value[to] = value[v] + factor;
                if (dfs(graph, to, value))
                    return 1;
            } else if (abs(value[to] - value[v] - factor) > 1e-9) {
                return 1;
            }
        }
        return 0;
    }

public:
    bool checkContradictions(vector<vector<string>> &equations, vector<double> &factors) {
        unordered_map<string, set<pair<string, double>>> graph;
        for (int i = 0; i < equations.size(); i++) {
            graph[equations[i][0]].insert({ equations[i][1], log(1 / factors[i]) });
            graph[equations[i][1]].insert({ equations[i][0], log(factors[i]) });
        }
        
        unordered_map<string, double> value;
        for (auto &[v, _] : graph) {
            if (!value.count(v)) {
                value[v] = 0;
                if (dfs(graph, v, value))
                    return 1;
            }
        }

        return 0;
    }
};