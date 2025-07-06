class Solution {
    bool checkCode(string &code) {
        for (char c : code)
            if (!isalnum(c) && c != '_')
                return 0;
        return !code.empty();
    }

    bool checkLine(string &line) {
        return line == "electronics" || line == "grocery" || line == "pharmacy" || line == "restaurant";
    }

public:
    vector<string> validateCoupons(vector<string> &code, vector<string> &line, vector<bool> &isActive) {
        vector<int> order;
        for (int i = 0; i < code.size(); i++)
            if (checkCode(code[i]) && checkLine(line[i]) && isActive[i])
                order.push_back(i);
        
        sort(order.begin(), order.end(), [&](int a, int b) {
            if (line[a] != line[b])
                return line[a] < line[b];
            return code[a] < code[b];
        });

        vector<string> res;
        for (int i : order)
            res.push_back(code[i]);
        return res;
    }
};