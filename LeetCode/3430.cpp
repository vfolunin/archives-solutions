class Solution {
    long long getCount(long long l, long long r, long long limit) {
        l = min(l, limit);
        r = min(r, limit);
        long long extra = max(l + r - 1 - limit, 0LL);
        return l * r - extra * (extra + 1) / 2; 
    }

public:
    long long minMaxSubarraySum(vector<int> &a, int limit) {
        vector<int> lMin(a.size(), -1), lMax(a.size(), -1);
        vector<int> stackMin, stackMax;

        for (int i = a.size() - 1; i >= 0; i--) {
            while (!stackMin.empty() && a[stackMin.back()] <= a[i]) {
                lMin[stackMin.back()] = i;
                stackMin.pop_back();
            }
            stackMin.push_back(i);

            while (!stackMax.empty() && a[stackMax.back()] >= a[i]) {
                lMax[stackMax.back()] = i;
                stackMax.pop_back();
            }
            stackMax.push_back(i);
        }

        vector<int> rMin(a.size(), a.size()), rMax(a.size(), a.size());
        stackMin.clear();
        stackMax.clear();

        for (int i = 0; i < a.size(); i++) {
            while (!stackMin.empty() && a[stackMin.back()] < a[i]) {
                rMin[stackMin.back()] = i;
                stackMin.pop_back();
            }
            stackMin.push_back(i);
            
            while (!stackMax.empty() && a[stackMax.back()] > a[i]) {
                rMax[stackMax.back()] = i;
                stackMax.pop_back();
            }
            stackMax.push_back(i);
        }

        long long res = 0;
        for (int i = 0; i < a.size(); i++) {
            res += a[i] * getCount(i - lMin[i], rMin[i] - i, limit);
            res += a[i] * getCount(i - lMax[i], rMax[i] - i, limit);
        }
        return res;
    }
};