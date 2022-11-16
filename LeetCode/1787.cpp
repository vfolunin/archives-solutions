class Solution {
public:
    int minChanges(vector<int> &a, int width) {
        vector<int> size(width);
        vector<vector<int>> count(width, vector<int>(1024));
        vector<unordered_set<int>> values(width);
                
        for (int i = 0; i < a.size(); i++) {
            size[i % width]++;
            count[i % width][a[i]]++;
            values[i % width].insert(a[i]);
        }
        
        vector<vector<int>> cost(width, vector<int>(1024, 1e9));
        
        for (int xorSum = 0; xorSum < 1024; xorSum++)
            cost[0][xorSum] = size[0] - count[0][xorSum];
        
        for (int i = 1; i < width; i++) {
            int minPrevCost = *min_element(cost[i - 1].begin(), cost[i - 1].end());

            for (int xorSum = 0; xorSum < 1024; xorSum++) {
                for (int value : values[i])
                    cost[i][xorSum] = min(cost[i][xorSum], cost[i - 1][xorSum ^ value] + size[i] - count[i][value]);

                cost[i][xorSum] = min(cost[i][xorSum], minPrevCost + size[i]);
            }
        }
        
        return cost[width - 1][0];
    }
};