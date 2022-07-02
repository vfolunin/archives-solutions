class Solution {
public:
    int maxArea(int h, int w, vector<int> &horizontalCuts, vector<int> &verticalCuts) {
        sort(horizontalCuts.begin(), horizontalCuts.end());
        int y = horizontalCuts[0];
        for (int i = 1; i < horizontalCuts.size(); i++)
            y = max(y, horizontalCuts[i] - horizontalCuts[i - 1]);
        y = max(y, h - horizontalCuts.back());
        
        sort(verticalCuts.begin(), verticalCuts.end());
        int x = verticalCuts[0];
        for (int i = 1; i < verticalCuts.size(); i++)
            x = max(x, verticalCuts[i] - verticalCuts[i - 1]);
        x = max(x, w - verticalCuts.back());
        
        int mod = 1e9 + 7;
        return 1LL * y * x % mod;
    }
};