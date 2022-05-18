class Solution {
public:
    int countGoodRectangles(vector<vector<int>> &rectangles) {
        int resSize = 0, resCount = 0;
        
        for (vector<int> &rectangle : rectangles) {
            int size = min(rectangle[0], rectangle[1]);
            if (resSize < size) {
                resSize = size;
                resCount = 1;
            } else if (resSize == size) {
                resCount++;
            }
        }
        
        return resCount;
    }
};