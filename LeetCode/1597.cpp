class Solution {
    string toPostfix(string &s) {
        string postfix, stack;    
        for (char c : s) {
            if (isdigit(c)) {
                postfix.push_back(c);
            } else if (c == '(') {
                stack.push_back(c);
            } else if (c == ')') {
                while (stack.back() != '(') {
                    postfix.push_back(stack.back());
                    stack.pop_back();
                }
                stack.pop_back();
            } else {
                while (!stack.empty() && stack.back() != '(' && (c == '+' || c == '-' || stack.back() == '*' || stack.back() == '/')) {
                    postfix.push_back(stack.back());
                    stack.pop_back();
                }
                stack.push_back(c);
            }
        }
        postfix.insert(postfix.end(), stack.rbegin(), stack.rend());    
        return postfix;
    }

public:
    Node *expTree(string &s) {
        vector<Node *> stack;
        for (char c : toPostfix(s)) {
            if (isdigit(c)) {
                stack.push_back(new Node(c));
            } else {
                Node *r = stack.back();
                stack.pop_back();
                Node *l = stack.back();
                stack.pop_back();
                stack.push_back(new Node(c, l, r));
            }
        }
        return stack.back();
    }
};