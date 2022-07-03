class Solution {
public:
    int totalSteps(vector<int> &a) {
        vector<int> time(a.size()), stack;
        
        for (int i = a.size() - 1; i >= 0; i--) {
            while (!stack.empty() && a[i] > a[stack.back()]) {
                time[i] = max(time[i] + 1, time[stack.back()]);
                stack.pop_back();
            }
            stack.push_back(i);
        }
        
        return *max_element(time.begin(), time.end());
    }
};