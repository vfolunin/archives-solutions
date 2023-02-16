class Solution {
public:
    bool verifyPreorder(vector<int> &preorder) {
        int from = 0;
        vector<int> stack;

        for (int value : preorder) {
            if (value < from)
                return 0;
            while (!stack.empty() && stack.back() < value) {
                from = stack.back();
                stack.pop_back();
            }
            stack.push_back(value);
        }

        return 1;
    }
};