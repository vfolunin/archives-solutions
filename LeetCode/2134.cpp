class Solution {
public:
    int minSwaps(vector<int> &a) {
        int ones = count(a.begin(), a.end(), 1);
        a.insert(a.end(), a.begin(), a.end());
        
        int window = count(a.begin(), a.begin() + ones, 1);
        int res = ones - window;
        
        for (int i = ones; i < a.size(); i++) {
            window += a[i] - a[i - ones];
            res = min(res, ones - window);
        }
        
        return res;
    }
};