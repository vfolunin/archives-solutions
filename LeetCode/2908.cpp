class Solution {
public:
    int minimumSum(vector<int> &a) {
        int res = 1e9;

        for (int i = 0; i < a.size(); i++)
            for (int j = i + 1; j < a.size(); j++)
                for (int k = j + 1; k < a.size(); k++)
                    if (a[i] < a[j] && a[j] > a[k])
                        res = min(res, a[i] + a[j] + a[k]);
                        
        return res != 1e9 ? res : -1;
    }
};