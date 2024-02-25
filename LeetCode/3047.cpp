class Solution {
public:
    long long largestSquareArea(vector<vector<int>> &bottomLeft, vector<vector<int>> &topRight) {
        int res = 0;
        for (int i = 0; i < bottomLeft.size(); i++) {
            for (int j = i + 1; j < bottomLeft.size(); j++) {
                int w = min(topRight[i][0], topRight[j][0]) - max(bottomLeft[i][0], bottomLeft[j][0]);
                int h = min(topRight[i][1], topRight[j][1]) - max(bottomLeft[i][1], bottomLeft[j][1]);
                res = max(res, min(w, h));
            }
        }
        return 1LL * res * res;
    }
};