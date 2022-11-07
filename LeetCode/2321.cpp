class Solution {
    int solve(vector<int> &a, vector<int> &b) {
        int sum = 0, curDelta = 0, delta = 0;
        for (int i = 0; i < a.size(); i++) {
            sum += a[i];
            curDelta = max(curDelta + b[i] - a[i], 0);
            delta = max(delta, curDelta);
        }
        return sum + delta;
    }
    
public:
    int maximumsSplicedArray(vector<int> &a, vector<int> &b) {
        return max(solve(a, b), solve(b, a));
    }
};