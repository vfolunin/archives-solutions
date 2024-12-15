class Solution {
public:
    int beautifulSplits(vector<int> &a) {
        vector<vector<int>> lcp(a.size(), vector<int>(a.size()));
        for (int i = a.size() - 1; i >= 0; i--)
            for (int j = a.size() - 1; j >= 0; j--)
                if (a[i] == a[j])
                    lcp[i][j] = 1 + (i + 1 < a.size() && j + 1 < a.size() ? lcp[i + 1][j + 1] : 0);
        
        int res = 0;
        for (int i = 1; i < a.size(); i++)
            for (int j = i + 1; j < a.size(); j++)
                res += lcp[0][i] >= i && i <= j - i || lcp[i][j] >= j - i;
        return res;
    }
};