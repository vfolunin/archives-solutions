class Solution {
public:
    int maxScore(vector<int> &a) {
        sort(a.rbegin(), a.rend());

        long long sum = 0;
        int res = 0;
        
        for (int value : a) {
            sum += value;
            res += sum > 0;
        }

        return res;
    }
};