class Solution {
public:
    vector<int> findBuildings(vector<int> &a) {
        vector<int> stack;
        for (int i = 0; i < a.size(); i++) {
            while (!stack.empty() && a[stack.back()] <= a[i])
                stack.pop_back();
            stack.push_back(i);
        }
        return stack;
    }
};