class Solution {
public:
    int triangleNumber(vector<int> &a) {
        sort(a.begin(), a.end());
        
        int res = 0;
        for (int i = 0; i < a.size(); i++)
            for (int j = i + 1; j < a.size(); j++)
                res += max<int>(lower_bound(a.begin(), a.end(), a[i] + a[j]) - a.begin() - j - 1, 0);
        
        return res;
    }
};