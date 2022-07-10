class Solution {
public:
    long long maxMatrixSum(vector<vector<int>> &a) {
        long long sum = 0, negCount = 0, minValue = 1e9;
        
        for (int y = 0; y < a.size(); y++) {
            for (int x = 0; x < a.size(); x++) {
                sum += abs(a[y][x]);
                negCount += a[y][x] < 0;
                minValue = min<long long>(minValue, abs(a[y][x]));
            }
        }
        
        if (negCount % 2)
            sum -= 2 * minValue;
        
        return sum;
    }
};