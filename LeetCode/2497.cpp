class Solution {
public:
    int maxStarSum(vector<int> &value, vector<vector<int>> &edges, int limit) {
        vector<multiset<int>> neighborValues(value.size());
        vector<int> neigborValueSum = value;

        for (vector<int> &edge : edges) {
            int a = edge[0], b = edge[1];

            if (value[b] > 0) {
                neighborValues[a].insert(value[b]);
                neigborValueSum[a] += value[b];
                if (neighborValues[a].size() > limit) {
                    neigborValueSum[a] -= *neighborValues[a].begin();
                    neighborValues[a].erase(neighborValues[a].begin());
                }
            }

            if (value[a] > 0) {
                neighborValues[b].insert(value[a]);
                neigborValueSum[b] += value[a];
                if (neighborValues[b].size() > limit) {
                    neigborValueSum[b] -= *neighborValues[b].begin();
                    neighborValues[b].erase(neighborValues[b].begin());
                }
            }
        }

        return *max_element(neigborValueSum.begin(), neigborValueSum.end());
    }
};