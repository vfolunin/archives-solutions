class Solution {
public:
    bool isRectangleCover(vector<vector<int>> &rectangles) {
        int yMin = 1e6, xMin = 1e6, yMax = -1e6, xMax = -1e6;
        long long area = 0;
        map<pair<int, int>, int> count;
        
        for (vector<int> &rectangle : rectangles) {
            yMin = min(yMin, rectangle[0]);
            xMin = min(xMin, rectangle[1]);
            yMax = max(yMax, rectangle[2]);
            xMax = max(xMax, rectangle[3]);
            
            area += 1LL * (rectangle[2] - rectangle[0]) * (rectangle[3] - rectangle[1]);
            
            count[{ rectangle[0], rectangle[1] }]++;
            count[{ rectangle[0], rectangle[3] }]++;
            count[{ rectangle[2], rectangle[1] }]++;
            count[{ rectangle[2], rectangle[3] }]++;
        }
        
        int oddCount = 0;
        for (auto &[pair, count] : count)
            oddCount += count % 2;
        
        return area == 1LL * (yMax - yMin) * (xMax - xMin) && oddCount == 4 &&
               count[{ yMin, xMin }] % 2 && count[{ yMin, xMax }] % 2 &&
               count[{ yMax, xMin }] % 2 && count[{ yMax, xMax }] % 2;
    }
};