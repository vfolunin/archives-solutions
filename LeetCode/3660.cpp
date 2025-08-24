class Solution {
public:
    vector<int> maxValue(vector<int> &a) {
        vector<int> lMax = a;
        for (int i = 1; i < a.size(); i++) 
            lMax[i] = max(lMax[i - 1], lMax[i]);

        vector<int> rMin = a;
        for (int i = (int)a.size() - 2; i >= 0; i--) 
            rMin[i] = min(rMin[i], rMin[i + 1]);

        vector<int> res = lMax;
        for (int i = (int)a.size() - 2; i >= 0; i--)
            if (res[i] > rMin[i + 1])
                res[i] = res[i + 1];
        return res;
    }
};