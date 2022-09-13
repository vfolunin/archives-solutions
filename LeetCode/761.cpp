class Solution {
public:
    string makeLargestSpecial(string &s) {
        vector<vector<string>> stack = { { "" } };
        int balance = 0;

        for (char c : s) {
            if (c == '1') {
                stack[balance].back() += c;
                balance++;
                if (stack.size() == balance)
                    stack.push_back({ "" });
            } else {
                sort(stack[balance].rbegin(), stack[balance].rend());
                for (string &part : stack[balance])
                    stack[balance - 1].back() += part;
                stack[balance - 1].back() += c;

                stack[balance] = { "" };
                stack[balance - 1].emplace_back();
                balance--;
            }
        }

        string res;
        sort(stack[0].rbegin(), stack[0].rend());
        for (string &part : stack[0])
            res += part;
        return res;
    }
};