class Solution {
public:
    int minMovesToSeat(vector<int> &a, vector<int> &b) {
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        
        int res = 0;
        for (int i = 0; i < a.size(); i++)
            res += abs(a[i] - b[i]);
        
        return res;
    }
};