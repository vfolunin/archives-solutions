class Solution {
public:
    int findBlackPixel(vector<vector<char>> &a, int target) {
        int h = a.size(), w = a[0].size();
        
        map<vector<char>, int> count;
        vector<int> rowSum = vector<int>(h);
        vector<int> colSum = vector<int>(w);

        for (int y = 0; y < h; y++) {
            count[a[y]]++;
            for (int x = 0; x < w; x++) {
                if (a[y][x] == 'B') {
                    rowSum[y]++;
                    colSum[x]++;
                }
            }
        }

        int res = 0;
        for (int y = 0; y < h; y++)
            if (rowSum[y] == target && count[a[y]] == target)
                for (int x = 0; x < w; x++)
                     res += a[y][x] == 'B' && colSum[x] == target;
        return res;
    }
};
