class Solution {
public:
    int minimizeConcatenatedLength(vector<string> &a) {
        vector<vector<int>> sLen(26, vector<int>(26, 1e9));
        sLen[a[0].front() - 'a'][a[0].back() - 'a'] = a[0].size();
        
        for (int i = 1; i < a.size(); i++) {
            int wl = a[i].front() - 'a';
            int wr = a[i].back() - 'a';
            int wLen = a[i].size();

            vector<vector<int>> nextSLen(26, vector<int>(26, 1e9));
            
            for (int sl = 0; sl < 26; sl++) {
                for (int sr = 0; sr < 26; sr++) {
                    nextSLen[wl][sr] = min(nextSLen[wl][sr], wLen - (wr == sl) + sLen[sl][sr]);
                    nextSLen[sl][wr] = min(nextSLen[sl][wr], sLen[sl][sr] - (sr == wl) + wLen);
                }
            }
            
            sLen.swap(nextSLen);
        }
        
        int res = 1e9;
        for (int l = 0; l < 26; l++)
            for (int r = 0; r < 26; r++)
                res = min(res, sLen[l][r]);
        return res;
    }
};