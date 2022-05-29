class Solution {
public:
    int evalRPN(vector<string> &tokens) {
        vector<int> stack;
        
        for (string &token : tokens) {
            if (isdigit(token.back())) {
                stack.push_back(stoi(token));
            } else {
                int b = stack.back();
                stack.pop_back();
                int a = stack.back();
                
                if (token == "+")
                    stack.back() = a + b;
                else if (token == "-")
                    stack.back() = a - b;
                else if (token == "*")
                    stack.back() = a * b;
                else
                    stack.back() = a / b;
            }
        }
        
        return stack.back();
    }
};