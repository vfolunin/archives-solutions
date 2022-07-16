class Solution {
public:
    int leastBricks(vector<vector<int>> &a) {
        unordered_map<long long, int> count;
        int maxCount = 0;
        
        for (vector<int> &row : a) {
            long long sum = 0;
            for (int i = 0; i + 1 < row.size(); i++) {
                sum += row[i];
                maxCount = max(maxCount, ++count[sum]);
            }
        }
        
        return a.size() - maxCount;
    }
};