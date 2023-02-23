class Solution {
public:
    string findTheString(vector<vector<int>> &lcp) {
        int size = lcp.size();

        vector<vector<int>> equal(size, vector<int>(size, 1));
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                if (lcp[i][j] != lcp[j][i])
                    return "";
                
                int iTo = i + lcp[i][j];
                int jTo = j + lcp[i][j];
                
                if (iTo > size || jTo > size)
                    return "";
                
                if (iTo < size && jTo < size)
                    equal[iTo][jTo] = equal[jTo][iTo] = 0;
            }
        }

        string res(size, 'a');
        for (int i = 1; i < size; i++) {
            vector<int> used(26);
            for (int j = 0; j < i; j++)
                if (!equal[i][j])
                    used[res[j] - 'a'] = 1;

            if (auto it = find(used.begin(), used.end(), 0); it != used.end())
                res[i] = 'a' + it - used.begin();
            else
                return "";
        }
        
        for (int i = size - 1; i >= 0; i--) {
            for (int j = size - 1; j >= 0; j--) {
                int lcpValue = (res[i] == res[j]);
                if (lcpValue && i + 1 < size && j + 1 < size)
                    lcpValue += lcp[i + 1][j + 1];
                    
                if (lcpValue != lcp[i][j])
                    return "";
            }
        }
        
        return res;
    }
};