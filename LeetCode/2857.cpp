class Solution {
public:
    int countPairs(vector<vector<int>> &points, int sum) {
        map<pair<int, int>, int> count;
        long long res = 0;

        for (vector<int> &point : points) {
            int x = point[0], y = point[1];            
            for (int sumX = 0, sumY = sum; sumX <= sum; sumX++, sumY--)
                res += count[{ x ^ sumX, y ^ sumY }];            
            count[{ x, y }]++;
        }
        
        return res;
    }
};