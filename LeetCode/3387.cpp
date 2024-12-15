class Solution {
    void fordBellman(vector<vector<string>> &edges, vector<double> &rates, unordered_map<string, double> &count) {
        for (int i = 0; i < edges.size(); i++) {
            for (int j = 0; j < edges.size(); j++) {
                if (count.count(edges[j][0]))
                    count[edges[j][1]] = max(count[edges[j][1]], count[edges[j][0]] * rates[j]);
                if (count.count(edges[j][1]))
                    count[edges[j][0]] = max(count[edges[j][0]], count[edges[j][1]] / rates[j]);
            }
        }
    }

public:
    double maxAmount(string &start,
                     vector<vector<string>> &edges1, vector<double> &rates1,
                     vector<vector<string>> &edges2, vector<double> &rates2) {
        unordered_map<string, double> count;
        count[start] = 1;

        fordBellman(edges1, rates1, count);
        fordBellman(edges2, rates2, count);

        return count[start];
    }
};