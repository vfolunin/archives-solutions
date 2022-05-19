class Solution {
public:
    int heightChecker(vector<int> &a) {
        vector<int> sortedA = a;
        sort(sortedA.begin(), sortedA.end());
        
        int res = 0;
        for (int i = 0; i < a.size(); i++)
            res += a[i] != sortedA[i];
        return res;
    }
};