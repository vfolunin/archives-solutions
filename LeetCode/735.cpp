class Solution {
public:
    vector<int> asteroidCollision(vector<int> &a) {
        vector<int> stack;
        
        for (int value : a) {
            if (stack.empty() || stack.back() < 0 || value > 0) {
                stack.push_back(value);
            } else {
                while (!stack.empty() && stack.back() > 0 && stack.back() < -value)
                    stack.pop_back();
                if (stack.empty() || stack.back() < 0)
                    stack.push_back(value);
                else if (stack.back() == -value)
                    stack.pop_back();
            }
        }
        
        return stack;
    }
};