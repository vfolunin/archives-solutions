class Solution {
    int getLcpSize(string &a, string &b) {
        int res = 0;
        while (res < a.size() && res < b.size() && a[res] == b[res])
            res++;
        return res;
    }

public:
    vector<int> longestCommonPrefix(vector<string> &a) {
        if (a.size() == 1)
            return { 0 };

        vector<int> lcpSize(a.size() - 1);
        for (int i = 0; i < lcpSize.size(); i++)
            lcpSize[i] = getLcpSize(a[i], a[i + 1]);

        vector<int> lcpSizeL(a.size());
        for (int i = 1; i < lcpSizeL.size(); i++)
            lcpSizeL[i] = max(lcpSizeL[i - 1], lcpSize[i - 1]);

        vector<int> lcpSizeR(a.size());
        for (int i = (int)lcpSizeR.size() - 2; i >= 0; i--)
            lcpSizeR[i] = max(lcpSizeR[i + 1], lcpSize[i]);

        vector<int> res = { lcpSizeR[1] };
        for (int i = 1; i + 1 < lcpSizeR.size(); i++)
            res.push_back(max({ lcpSizeL[i - 1], getLcpSize(a[i - 1], a[i + 1]), lcpSizeR[i + 1] }));
        res.push_back(lcpSizeL[lcpSizeL.size() - 2]);
        return res;
    }
};