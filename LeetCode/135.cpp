class Solution {
public:
    int candy(vector<int> &a) {
        vector<int> res(a.size(), 1);
        
        for (int i = 1; i < a.size(); i++)
            if (a[i - 1] < a[i])
                res[i] = res[i - 1] + 1;
        
        for (int i = (int)a.size() - 2; i >= 0; i--)
            if (a[i] > a[i + 1])
                res[i] = max(res[i], res[i + 1] + 1);
        
        int resSum = 0;
        for (int value : res)
            resSum += value;
        
        return resSum;
    }
};