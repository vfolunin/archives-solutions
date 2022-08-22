class Solution {
public:
    long long interchangeableRectangles(vector<vector<int>> &rectangles) {
        map<pair<int, int>, long long> count;
        
        for (vector<int> &rectangle : rectangles) {
            int d = gcd(rectangle[0], rectangle[1]);
            count[{ rectangle[0] / d, rectangle[1] / d }]++;
        }
        
        long long res = 0;
        for (auto &[rectangle, count] : count)
            res += count * (count - 1) / 2;
        return res;
    }
};