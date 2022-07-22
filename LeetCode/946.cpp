class Solution {
public:
    bool validateStackSequences(vector<int> &pushed, vector<int> &popped) {
        vector<int> stack;
        for (int i = 0, j = 0; i < pushed.size(); i++) {
            stack.push_back(pushed[i]);
            while (!stack.empty() && j < popped.size() && stack.back() == popped[j]) {
                stack.pop_back();
                j++;
            }
        }
        return stack.empty();
    }
};