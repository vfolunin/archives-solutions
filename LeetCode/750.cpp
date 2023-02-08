class Solution {
public:
    int countCornerRectangles(vector<vector<int>> &a) {
        int res = 0;
        for (int y1 = 0; y1 < a.size(); y1++) {
            for (int y2 = y1 + 1; y2 < a.size(); y2++) {
                int count = 0;
                for (int x = 0; x < a[0].size(); x++) {
                    if (a[y1][x] && a[y2][x]) {
                        res += count;
                        count++;
                    }
                } 
            }
        }
        return res;
    }
};