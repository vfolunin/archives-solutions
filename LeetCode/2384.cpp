class Solution {
public:
    string largestPalindromic(string &s) {
        vector<int> count(10);
        for (char c : s)
            count[c - '0']++;
        
        string left, center;
        for (int i = count.size() - 1; i >= 0; i--) {
            left += string(count[i] / 2, i + '0');
            if (count[i] % 2 && center.empty())
                center = string(1, i + '0');
        }
        
        if (left[0] == '0')
            return !center.empty() ? center : "0";
        
        string right = left;
        reverse(right.begin(), right.end());
        return left + center + right;
    }
};