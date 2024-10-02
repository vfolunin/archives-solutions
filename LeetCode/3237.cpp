class Solution {
public:
    vector<int> simulationResult(vector<int> &order, vector<int> &queries) {
        vector<int> time(order.size(), -1);
        for (int i = 0; i < queries.size(); i++)
            time[queries[i] - 1] = i;
        
        stable_sort(order.begin(), order.end(), [&](int a, int b) {
            return time[a - 1] > time[b - 1];
        });
        return order;
    }
};