class Solution {
public:
    long long maxArrayValue(vector<int> &a) {
        long long res = a.back();

        for (int i = (int)a.size() - 2; i >= 0; i--) {
            if (res < a[i])
                res = a[i];
            else
                res += a[i];
        }
        
        return res;
    }
};