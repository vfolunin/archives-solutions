class Solution {
public:
    int maxValueAfterReverse(vector<int> &a) {
        int sum = 0;
        for (int i = 0; i + 1 < a.size(); i++)
            sum += abs(a[i] - a[i + 1]);
        
        int delta = 0;
        for (int i = 0; i + 1 < a.size(); i++) {
            delta = max(delta, abs(a[0] - a[i + 1]) - abs(a[i] - a[i + 1]));
            delta = max(delta, abs(a.back() - a[i]) - abs(a[i] - a[i + 1]));
        }
        
        int minP = 1e9, maxP = -1e9;
        for (int i = 0; i + 1 < a.size(); i++) {
            minP = min(minP, max(a[i], a[i + 1]));
            maxP = max(maxP, min(a[i], a[i + 1]));
        }
        delta = max(delta, 2 * (maxP - minP));
        
        return sum + delta;
    }
};