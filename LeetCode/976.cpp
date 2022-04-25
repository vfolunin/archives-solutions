class Solution {
public:
    int largestPerimeter(vector<int> &a) {
        sort(a.begin(), a.end());
        
        int res = 0;
        for (int i = 0; i + 2 < a.size(); i++)
            if (a[i] + a[i + 1] > a[i + 2])
                res = max(res, a[i] + a[i + 1] + a[i + 2]);
        return res;
    }
};