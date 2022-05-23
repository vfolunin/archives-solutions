class Solution {
public:
    int findMaxForm(vector<string> &words, int k0, int k1) {
        vector<vector<int>> maxSize(k0 + 1, vector<int>(k1 + 1));
        for (string &word : words) {
            int w0 = 0, w1 = 0;
            for (char c : word) {
                if (c == '0')
                    w0++;
                else
                    w1++;
            }
            
            for (int c0 = k0; c0 >= w0; c0--)
                for (int c1 = k1; c1 >= w1; c1--)
                    maxSize[c0][c1] = max(maxSize[c0][c1], maxSize[c0 - w0][c1 - w1] + 1);
        }
        
        int res = 0;
        for (int c0 = 0; c0 <= k0; c0++)
            for (int c1 = 0; c1 <= k1; c1++)
                res = max(res, maxSize[c0][c1]);
        return res;
    }
};