class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int> &a) {
        vector<int> stack;
        for (int value : a) {
            while (!stack.empty() && gcd(stack.back(), value) > 1) {
                value = lcm(stack.back(), value);
                stack.pop_back();
            }
            stack.push_back(value);
        }
        return stack;
    }
};