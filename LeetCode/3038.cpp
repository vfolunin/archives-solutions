class Solution {
public:
    int maxOperations(vector<int> &a) {
        int res = 0;
        for (int i = 0; i + 1 < a.size() && a[i] + a[i + 1] == a[0] + a[1]; i += 2)
            res++;
        return res;
    }
};