class Solution {
public:
    int maxRotateFunction(vector<int> &a) {
        int size = a.size(), sum = 0, cur = 0;
        for (int i = 0; i < size; i++) {
            sum += a[i];
            cur += i * a[i];
        }
        
        int res = cur;
        while (!a.empty()) {
            cur += sum - size * a.back();
            a.pop_back();
            res = max(res, cur);
        }
        
        return res;
    }
};