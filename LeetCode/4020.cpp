class Solution {
public:
    int elevatorRequests(int n, vector<int> &a) {
        int res = a[0];
        for (int i = 1; i < a.size(); i++)
            res += abs(a[i - 1] - a[i]);
        return res;
    }
};