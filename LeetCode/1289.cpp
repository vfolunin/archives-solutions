class Solution {
public:
    int minFallingPathSum(vector<vector<int>> &a) {
        int size = a.size();
        vector<int> prevSum = a[0];
        
        for (int y = 1; y < size; y++) {
            vector<int> sum(size, 1e9);
            
            for (int prevX = 0; prevX < size; prevX++)
                for (int x = 0; x < size; x++)
                    if (prevX != x)
                        sum[x] = min(sum[x], prevSum[prevX] + a[y][x]);
            
            prevSum.swap(sum);
        }
        
        return *min_element(prevSum.begin(), prevSum.end());
    }
};