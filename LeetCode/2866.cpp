class Solution {
public:
    long long maximumSumOfHeights(vector<int> &a) {
        vector<long long> l(a.size());
        vector<pair<long long, long long>> stack;
        long long sum = 0;
        
        for (int i = 0; i < a.size(); i++) {
            long long count = 1;
            while (!stack.empty() && stack.back().first > a[i]) {
                sum -= stack.back().first * stack.back().second;
                count += stack.back().second;
                stack.pop_back();
            }
            
            sum += a[i] * count;
            stack.push_back({ a[i], count });
            l[i] = sum;
        }
        
        vector<long long> r(a.size());
        stack.clear();
        sum = 0;
        
        for (int i = a.size() - 1; i >= 0; i--) {
            long long count = 1;
            while (!stack.empty() && stack.back().first > a[i]) {
                sum -= stack.back().first * stack.back().second;
                count += stack.back().second;
                stack.pop_back();
            }
            
            sum += a[i] * count;
            stack.push_back({ a[i], count });
            r[i] = sum;
        }
        
        long long res = 0;
        for (int i = 0; i < a.size(); i++)
            res = max(res, l[i] + r[i] - a[i]);
        return res;
    }
};