class Solution {
public:
    bool isBalanced(string &s) {
        vector<int> sum(2);
        for (int i = 0; i < s.size(); i++)
            sum[i % 2] += s[i] - '0';
        return sum[0] == sum[1];
    }
};