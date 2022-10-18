class Solution {
public:
    int minPatches(vector<int> &a, long long limit) {
        int res = 0;        
        for (long long sum = 0, i = 0; sum < limit; ) {
            if (i < a.size() && a[i] <= sum + 1) {
                sum += a[i];
                i++;
            } else {
                sum += sum + 1;
                res++;
            }
        }        
        return res;
    }
};